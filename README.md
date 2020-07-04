# CompressionAlgorithm
Loseless compression algorithm using Huffman Coding written in C++.

# Output:

Encoding Table:

Original      | Encoding
------------- | -------------
0x64          | 0111
0x35          | 01011
0x56          | 0110
0x45          | 00100
0x00          | 000
0x74          | 00101
0x04          | 0100
0x09          | 0011
0x03          | 01010

Original Message:

3 74 4 4 4 35 35 64 64 64 64 0 0 0 0 0 56 45 56 56 56 9 9 9

Encoded Message:

01010 00101 0100 0100 0100 01011 01011 0111 0111 0111 0111 000 000 000 000 000 0110 00100 0110 0110 0110 0011 0011 0011


Original Size:          192 bits

Encoded Size:           96 bits

Compressions Ratio:     2.000000

Space Savings:          50%
