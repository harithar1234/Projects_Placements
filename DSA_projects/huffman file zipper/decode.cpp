#include <iostream>

#include "huffman.cpp"

using namespace std;

int main(int argc, char *argv[])
{
        
     // Check if the correct number of arguments is provided
    if (argc != 3)
    {
         cout << "Failed to detect Files"<< endl;
        return 1;
    }

    // Create an instance of the Huffman class
    huffman huffmanDecoder(argv[1], argv[2]);

    // Decompress the input file
    huffmanDecoder.decompress();

    // Print a success message
    cout << "Decompression completed successfully." << endl;

    return 0;
}
