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

Skills Gained:
* Deep Learning Fundamentals: gained a deep understanding of fundamental concepts in deep learning, including convolutional neural networks (CNNs), backpropagation, activation functions (ReLU, Softmax), loss functions (cross-entropy), and optimization algorithms (Vanilla SGD, Momentum, RMSprop).
* Neural Network Components: implemented various layers and components of a neural network, including convolutional layers, pooling layers, fully connected layers, and flattening layers. This demonstrates my grasp of the building blocks of modern neural networks.
* Gradient Descent Optimization: By implementing optimization algorithms like Vanilla SGD, Momentum, and RMSprop, learned how to update network parameters iteratively to minimize the loss function.
* Data Preprocessing: processed and prepared data for training and evaluation. This includes reshaping images, encoding labels into one-hot vectors, and splitting data into training and testing sets.
* Evaluation Metrics: calculated cross-entropy loss and accuracy as evaluation metrics to assess the performance of the model.
* Visualization: created t-SNE plots to visualize the feature vectors in a lower-dimensional space, helping to understand the distribution of data.

Tech Stack Used:
* Python: The primary programming language used for implementing the entire neural network and related functionalities.
* NumPy: Used for numerical computations and array manipulations.
* Matplotlib: Used for creating visualizations, such as plots and t-SNE visualizations.
* scikit-learn (sklearn): Utilized for t-SNE implementation and dimensionality reduction visualization.
* TensorFlow (potentially): TensorFlow might have been used for loading the MNIST dataset and preprocessing it, although it's not explicitly shown in the code.

Overall, my code demonstrates a comprehensive understanding of implementing a CNN from scratch and training it using different optimization algorithms. It's worth noting that while implementing these components from scratch is a great learning exercise, using established deep learning frameworks like TensorFlow or PyTorch can significantly simplify and optimize the development process for real-world projects.
