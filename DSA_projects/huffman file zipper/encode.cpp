#include <iostream>

#include "huffman.cpp"

using namespace std;

int main(int argc, char* argv[])
{
    // Check if the correct number of arguments is provided
    if (argc != 3)
    {
        cout << "Failed to detect Files" << endl;
        return 1;
    }

    // Create an instance of the Huffman class
    huffman huffmanEncoder(argv[1], argv[2]);

    // Compress the input file
    huffmanEncoder.compress();

    // Print a success message
    cout << "Compression completed successfully." << endl;

    return 0;
}
