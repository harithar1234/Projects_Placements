* This is a group project of 4 members.
* We implemented J-UNIWARD Stegnography (hstego) for our Web app.
* Implemented a pre-trained model on Alaska 2 dataset for JUNIWARD steganalysis.
* We have used pickel file generated from our trained neural network to implement the steganalysis in our app.

**My Contribution:** <br>
**DeepSteg: A Deep Learning approach to steganography detection** 
* Implemented steganalysis technique using Efficientnet-b2 pretrained model fine tuned on ALASKA dataset to detect JUNIWARD-encoded messages in JPEG images.
* Got Accuracy of 0.6 for trained model as it was trained using less data( with 20% of the data ) .
* Procedure:
  * The trained model detects whether a message was encoded using JUNIWARD in a given JPEG image.
  * The code trains and evaluates models for image steganalysis on the Alaska2 dataset.
  * The dataset is loaded and split into training and validation sets, with various image augmentation techniques applied.
  * It supports two model architectures: SRNet (custom model) and EfficientNet (pretrained model).
  * Training is performed using binary cross-entropy loss and the AdamW optimizer .
  * Evaluation metrics include loss and weighted AUC (area under the ROC curve).
  * The model assigns a score to each image, indicating the likelihood of hidden data.
  * EfficientNet-B2 pretrained model is used, fine-tuned on the Alaska2 dataset.
  * The implemented SRNet model, based on the provided architecture, is outperformed by the EfficientNet model.

The code handles challenges such as preprocessing and augmenting large-scale image datasets, designing and training deep learning models, and optimizing the training process.
The impact of the code is to assist in identifying hidden information within digital images, which can be useful for security, forensics, and data protection purposes.
