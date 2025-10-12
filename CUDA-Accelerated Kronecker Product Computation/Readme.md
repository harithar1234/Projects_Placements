
Implemented three optimized CUDA kernels (per-row, per-column, and per-element) for parallel computation of matrix Kronecker product (C = A ⊗ Bᵀ), leveraging 1D and 2D thread-block parallelism and efficient global memory access patterns to achieve up to 50× performance improvement over CPU implementations on 1024×1024 matrices.
