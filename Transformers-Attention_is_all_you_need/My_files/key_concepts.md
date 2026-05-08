# Transformer — Key Terms & Concepts Learned

- **Paper:** Vaswani et al., *Attention Is All You Need*, NeurIPS 2017 — [paper PDF](https://proceedings.neurips.cc/paper_files/paper/2017/file/3f5ee243547dee91fbd053c1c4a845aa-Paper.pdf)
- **Notes:** [hkproj/transformer-from-scratch-notes](https://github.com/hkproj/transformer-from-scratch-notes)
- **Video — Coding from scratch:** [Umar Jamil — YouTube](https://www.youtube.com/watch?v=ISNdQcPhsts)
- **Video — Model + Math + Inference + Training:** [Umar Jamil — YouTube playlist](https://www.youtube.com/watch?v=bCz4OMemCcA&list=PLs-ugvyV8JZrwaaTFjMRo_V_AQedX26HO)
- **Reference code:** [hkproj/pytorch-transformer](https://github.com/hkproj/pytorch-transformer)

---

## 1. Why Transformers (motivation)

| Concept | What it means |
|---|---|
| **Sequence-to-sequence (seq2seq)** | Map an input sequence (e.g., English sentence) to an output sequence (e.g., Italian sentence). |
| **Limitations of RNN/LSTM/GRU** | (1) Inherently sequential → no parallelism over time; (2) Long sequences → vanishing/exploding gradients; (3) Long-range dependencies are hard to capture; (4) Slow training. |
| **Transformer's answer** | Replace recurrence with **self-attention** so every token can attend to every other token in **one step**, fully parallelizable on GPU. |
| **Inductive bias removed** | No assumption of sequentiality → must inject **positional encoding** to recover order information. |

---

## 2. High-level architecture

| Term | Description |
|---|---|
| **Encoder–Decoder** | Encoder turns the source sequence into a contextualized representation; decoder generates the target sequence one token at a time using the encoder's output. |
| **N (number of layers)** | Number of stacked encoder/decoder blocks. Base model: **N = 6** on each side. |
| **`d_model`** | Embedding/hidden dimension that flows through the network. Base: **512**. |
| **`d_ff`** | Inner dimension of the position-wise feed-forward network. Base: **2048**. |
| **`h` (heads)** | Number of attention heads. Base: **8**. |
| **`d_k`, `d_v`** | Per-head key/value dimension. With `d_model=512`, `h=8` → `d_k = d_v = 64`. |
| **Dropout** | Applied to embeddings + positional encoding, attention weights, and sublayer outputs. Base: **0.1**. |

---

## 3. Input pipeline

### 3.1 Tokenization
| Term | Description |
|---|---|
| **Tokenizer** | Splits raw text into integer IDs. Project uses **word-level tokenizer** (HuggingFace `tokenizers`). |
| **Vocabulary** | Set of token-IDs. Different vocab for source and target language. |
| **Special tokens** | `[SOS]` start-of-sentence, `[EOS]` end-of-sentence, `[PAD]` padding, `[UNK]` unknown. |
| **Subword tokenization (mentioned)** | BPE / WordPiece / SentencePiece — handle out-of-vocabulary words; not used in this project but standard in modern LLMs. |

### 3.2 Input embedding
| Term | Description |
|---|---|
| **Embedding matrix** | Trainable lookup `nn.Embedding(vocab_size, d_model)` mapping each token-ID to a `d_model`-vector. |
| **Scaling by √`d_model`** | Embeddings are multiplied by `√d_model` (paper §3.4) — keeps variance stable when added to positional encoding. |

### 3.3 Positional encoding (PE)
| Term | Description |
|---|---|
| **Why positional encoding?** | Self-attention is **permutation-invariant** — the model has no notion of order without it. |
| **Sinusoidal PE (paper formula)** | `PE(pos, 2i) = sin(pos / 10000^(2i/d_model))`,  `PE(pos, 2i+1) = cos(pos / 10000^(2i/d_model))`. |
| **Why sin/cos at different frequencies?** | Each dimension is a sinusoid of a different wavelength → the model can learn relative positions; closed-form ⇒ generalizes to longer sequences than seen during training. |
| **Buffer (not trainable)** | PE is precomputed once and stored as a `register_buffer` — moves with `.to(device)` but is not a parameter. |
| **Learned PE (alternative)** | Some models (BERT) use trainable absolute positions instead. |

---

## 4. Attention — the core mechanism

### 4.1 Scaled dot-product attention
| Term | Description |
|---|---|
| **Query (Q), Key (K), Value (V)** | Three projections of the input. Intuition: each token issues a *query* asking "what should I attend to?", every other token presents a *key* describing itself, and supplies a *value* containing its content. |
| **Attention formula** | `Attention(Q, K, V) = softmax(Q · Kᵀ / √d_k) · V`. |
| **Why divide by √d_k?** | Prevents dot products from growing large in magnitude with bigger `d_k`, which would push softmax into low-gradient regions. |
| **Softmax over keys** | Each row of attention weights sums to 1 → a probability distribution over which tokens to read from. |
| **Attention weights matrix** | Shape `(seq_len, seq_len)` per head — interpretable; used in `attention_visual.ipynb`. |

### 4.2 Multi-head attention (MHA)
| Term | Description |
|---|---|
| **Linear projections `W_Q, W_K, W_V`** | Project `d_model → d_model`, then reshape into `h` heads of size `d_k = d_model/h`. |
| **Why multiple heads?** | Each head learns to attend to a different type of relationship (syntactic, semantic, positional, etc.) in a different subspace. |
| **Head concatenation** | Outputs of all heads are concatenated → projected back to `d_model` via `W_O`. |
| **Parameter count of MHA** | `4 × d_model²` (for Q, K, V, O projections), independent of `h`. |
| **Parallelism** | All heads are computed simultaneously as a single batched matrix multiply. |

### 4.3 Three uses of attention in the Transformer
| Variant | Where | Q comes from | K, V come from |
|---|---|---|---|
| **Encoder self-attention** | Each encoder layer | Encoder input | Encoder input |
| **Masked decoder self-attention** | Each decoder layer | Decoder input | Decoder input |
| **Encoder–decoder cross-attention** | Each decoder layer | Decoder hidden state | **Encoder output** (memory) |

---

## 5. Masking

| Term | Description |
|---|---|
| **Padding mask** | Hides `[PAD]` tokens so attention scores at padded positions are set to `-∞` before softmax → contribute zero probability. Used on both encoder and decoder. |
| **Causal mask (look-ahead mask)** | Upper-triangular mask used in **decoder self-attention** so position `t` cannot see positions `> t`. Implements teacher-forced autoregression during training. |
| **Combined decoder mask** | Padding mask **AND** causal mask, broadcast to `(B, 1, seq_len, seq_len)`. |
| **Implementation trick** | `attention_scores.masked_fill_(mask == 0, -1e9)` before softmax. |

---

## 6. Sublayer building blocks

| Component | Formula / shape |
|---|---|
| **Position-wise Feed-Forward (FFN)** | `FFN(x) = max(0, x W₁ + b₁) W₂ + b₂`. Inner dim `d_ff = 2048`. Applied **independently to every position**. |
| **Layer Normalization** | `y = α · (x − μ) / (σ + ε) + β`, with learnable `α`, `β`. Normalizes across the feature dimension, per token. |
| **Residual connection** | `y = x + Sublayer(x)` — solves vanishing gradients, lets deep stacks train. |
| **Pre-norm vs Post-norm** | Paper applies LayerNorm **after** the residual (post-norm). Most modern code (and this project) uses **pre-norm**: `y = x + Dropout(Sublayer(LayerNorm(x)))` — more stable training. |
| **Dropout placements** | (1) After embedding + PE; (2) on attention weights; (3) after each sublayer before the residual add. |

---

## 7. Encoder

| Term | Description |
|---|---|
| **Encoder block** | Two sublayers: (a) multi-head **self-attention**, (b) position-wise FFN — each wrapped with residual + LayerNorm. |
| **Encoder stack** | `N` such blocks → final `LayerNorm` → produces the **encoder output / memory** of shape `(B, src_len, d_model)`. |
| **Bidirectional context** | No causal mask in the encoder — every source token sees every other source token. |

---

## 8. Decoder

| Term | Description |
|---|---|
| **Decoder block** | Three sublayers: (a) masked multi-head **self-attention**, (b) **cross-attention** (Q from decoder, K/V from encoder memory), (c) position-wise FFN. |
| **Cross-attention** | This is *where the source language influences the target language*. Each target token queries the encoded source representation. |
| **Decoder stack** | `N` blocks → final `LayerNorm` → produces hidden states of shape `(B, tgt_len, d_model)`. |
| **Output projection** | `Linear(d_model → tgt_vocab_size)` produces logits over the target vocabulary. |
| **Weight tying (optional)** | Some implementations share weights between target embedding and output projection (not done in this project). |

---

## 9. Training

### 9.1 Teacher forcing
| Term | Description |
|---|---|
| **Teacher forcing** | During training the decoder input is the **ground-truth target shifted right** (prefixed with `[SOS]`); the loss is computed against the full target ending with `[EOS]`. |
| **Shifted-right convention** | `decoder_input = [SOS] y₁ y₂ … y_{T-1}`,  `label = y₁ y₂ … y_T [EOS]`. |
| **Label smoothing** | Replace one-hot target with `(1-ε)·onehot + ε/V`. ε = 0.1. Prevents overconfidence, improves BLEU and calibration. |
| **Loss function** | Cross-entropy over the target vocabulary, with `[PAD]` ignored via `ignore_index=PAD_ID`. |

### 9.2 Optimization
| Term | Description |
|---|---|
| **Adam optimizer** | β₁ = 0.9, β₂ = 0.98 (paper) / 0.999 (project default), ε = 1e-9. |
| **Noam learning-rate schedule (paper)** | `lr = d_model^(-0.5) · min(step^(-0.5), step · warmup^(-1.5))` — linear warmup then inverse-sqrt decay. |
| **Project schedule** | Fixed `lr = 1e-4` (simpler, works fine for this dataset size). |
| **Xavier (Glorot) initialization** | Applied to all weights with `dim > 1` → keeps variance of activations stable across layers. |
| **Gradient flow tools** | Residual connections + LayerNorm → enable training of deep stacks (12+ layers). |

### 9.3 Logging & evaluation
| Metric | Meaning |
|---|---|
| **Cross-entropy loss** | Optimization objective; lower is better. |
| **BLEU** | n-gram overlap with reference translation; higher is better. |
| **Word Error Rate (WER)** | Edit distance at word level. |
| **Character Error Rate (CER)** | Edit distance at character level. |
| **TensorBoard / W&B** | Used for live tracking of loss + validation metrics across epochs. |

---

## 10. Inference (autoregressive generation)

| Term | Description |
|---|---|
| **Autoregressive decoding** | Generate one token at a time; feed each generated token back as decoder input for the next step. |
| **Greedy decoding** | At each step pick `argmax` of logits. Fast but suboptimal — locally greedy choices can ruin global fluency. |
| **Beam search** | Keep top-`k` partial hypotheses (the *beam*) at each step, expand all of them, prune by sequence log-probability. Higher BLEU than greedy. |
| **Length normalization** | Beam scores divided by `length^α` to avoid bias toward shorter sequences. |
| **Top-k / nucleus (top-p) sampling** | Probabilistic decoding alternatives (used in LLM generation, not in this NMT project). |
| **Encoder caching** | Encoder is run **once**; only the decoder is re-run for each new generated token. |
| **KV-cache (mentioned)** | In modern LLM inference, past keys/values are cached to avoid recomputing attention over the prefix every step. |
| **Stopping criterion** | Generation stops when `[EOS]` is produced or `seq_len` is reached. |

---

## 11. Computational properties (paper Table 1)

| Layer type | Complexity per layer | Sequential ops | Max path length |
|---|---|---|---|
| **Self-Attention** | `O(n² · d)` | `O(1)` | `O(1)` |
| **Recurrent (RNN)** | `O(n · d²)` | `O(n)` | `O(n)` |
| **Convolutional** | `O(k · n · d²)` | `O(1)` | `O(log_k n)` |

| Term | Description |
|---|---|
| **`O(1)` path length** | Any two positions can interact in a single attention step — the key reason Transformers handle long-range dependencies so well. |
| **`O(n²)` memory** | Quadratic in sequence length — motivates sparse / linear / Flash attention variants in modern research. |

---

## 13. Quick mental model (one paragraph)

A Transformer turns each input token into a vector, **adds a positional code** so order is preserved, then runs the sequence through a stack of blocks. Each block lets every token **look at every other token via self-attention** (Q·Kᵀ → softmax → weighted sum of Vs across multiple heads), then **mixes information non-linearly per position** with a feed-forward network. **Residual connections + LayerNorm** keep deep stacks trainable. The encoder builds a fully bidirectional representation of the source. The decoder generates the target **left-to-right**, using a **causal mask** on its own self-attention and **cross-attention** to read from the encoder. A final linear layer projects to vocab logits. We train with **teacher-forced cross-entropy** + **label smoothing**, then **decode autoregressively** at inference time, optionally with **beam search**.

---

## 14. Glossary (one-liners — interview-ready)

- **Attention:** A weighted average of values, where weights come from a softmax over query–key dot products.
- **Self-attention:** Attention where Q, K, V all come from the same sequence.
- **Cross-attention:** Attention where Q comes from one sequence and K, V from another (decoder ← encoder).
- **Multi-head:** Run attention `h` times in parallel on different learned subspaces, then concatenate.
- **Causal mask:** Triangular mask that prevents looking at future tokens.
- **Padding mask:** Hides `[PAD]` tokens from attention.
- **Positional encoding:** Vector added to embeddings to inject token order.
- **Layer norm:** Per-token, per-feature normalization with learnable scale/shift.
- **Residual connection:** `y = x + f(x)` — preserves gradient flow.
- **Pre-norm:** LayerNorm inside the residual branch (modern, stable).
- **Teacher forcing:** Feed ground-truth previous tokens to the decoder during training.
- **Label smoothing:** Soften one-hot targets to discourage overconfidence.
- **Greedy decoding:** Argmax at each step.
- **Beam search:** Maintain top-`k` partial sequences ranked by log-prob.
- **BLEU:** n-gram precision-based MT metric.
- **KV cache:** Reuse past keys/values during autoregressive decoding for speed.

---

## 15. What I can confidently explain in an interview

- The exact tensor shapes flowing through every layer (`(B, seq_len, d_model)` → reshape into `(B, h, seq_len, d_k)` for attention → back to `(B, seq_len, d_model)`).
- Why we divide by `√d_k` and the consequence on softmax gradients.
- Why positional encodings are needed and why sinusoidal forms generalize beyond training length.
- The three places attention is used and how Q/K/V differ in each.
- How padding and causal masks are built and combined.
- The full training loop: tokenize → embed + PE → encoder → masked decoder + cross-attn → projection → label-smoothed CE loss → Adam step.
- The full inference loop: encode source once → loop: feed `[SOS]` + generated-so-far → take last logit → argmax (or beam) → append → stop on `[EOS]`.
- Trade-offs: parallelism vs `O(n²)` memory; pre-norm vs post-norm; greedy vs beam search.
