# CompressionAlgorithm
Loseless compression algorithm using Huffman Coding written in C++.

# Output:

Encoding Table:

64      0111
35      01011
56      0110
45      00100
0       000
74      00101
4       0100
9       0011
3       01010


Original Message:

3 74 4 4 4 35 35 64 64 64 64 0 0 0 0 0 56 45 56 56 56 9 9 9

Encoded Message:

01010 00101 0100 0100 0100 01011 01011 0111 0111 0111 0111 000 000 000 000 000 0110 00100 0110 0110 0110 0011 0011 0011


Original Size:          192 bits

Encoded Size:           96 bits

Compressions Ratio:     2.000000

Space Savings:          50%
