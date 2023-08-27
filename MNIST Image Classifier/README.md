The code that implements a convolutional neural network (CNN) from scratch using Python and NumPy. This code includes various functions for forward propagation, backward propagation, different optimization algorithms (Vanilla SGD, Momentum, RMSprop), loss calculation, and accuracy calculation. The code also implements training and testing loops for the CNN on the MNIST dataset.

Here's a summary of the main components and functionalities in the code:
* Convolutional Layer: The conv_forward and conv_backward functions implement the forward and backward propagation for a convolutional layer, respectively. The convolutional layer is used for feature extraction from the input images.
* Pooling Layer: The pool_forward and pool_backward functions implement the forward and backward propagation for a max-pooling layer, which reduces the spatial dimensions of the feature maps.
* Flattening Layer: The flat_forward and flat_backpropagation functions handle the flattening of the pooled feature maps to prepare them for the fully connected layers.
* Multi-Layer Perceptron (MLP): The MLP_forward and MLP_backward functions handle the forward and backward propagation of the fully connected layers, also known as the MLP part of the network.
* Optimization Algorithms: Your code includes implementations of three optimization algorithms: Vanilla SGD, Momentum, and RMSprop. These algorithms update the model parameters during training to minimize the loss.
* Loss Function: The cross_entropy_god function calculates the cross-entropy loss between predicted and actual labels.
* Accuracy Calculation: The accuracy_calc function computes the accuracy of the model's predictions on the test data.
* Complete Model Training Loop: The Complete_model function orchestrates the complete training and evaluation process. It includes multiple epochs, where each epoch consists of forward and backward passes, parameter updates, and evaluation of errors and accuracy.
* Data Preprocessing: The code preprocesses the MNIST dataset, including loading the data, reshaping the images, encoding the labels, and splitting the data into training and testing sets.

Overall, my code demonstrates a comprehensive understanding of implementing a CNN from scratch and training it using different optimization algorithms. It's worth noting that while implementing these components from scratch is a great learning exercise, using established deep learning frameworks like TensorFlow or PyTorch can significantly simplify and optimize the development process for real-world projects.
