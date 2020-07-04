#include <vector>
#include <unordered_map> 
#include <cstdint>
#include <string>
#include "main.hpp"
#include "frequencyOrder.hpp"
#include "Node.hpp"
#include "huffmanCoding.hpp"
#include "output.hpp"

using namespace std;

int byte_compress(uint8_t * data_ptr, int data_size) {

	vector<Node> v;
	frequencyOrder(v, data_ptr, data_size);

	// Build Huffman tree
	Node * parent = buildHuffmanTree(v);

	// Fill in encodings in tree
	parent->encode("0");
	unordered_map<uint8_t, string> encodings;
	createEncodingTable(parent, encodings);

	outputEncodingTable(encodings);
	outputOriginal(data_ptr, data_size);
	outputEncoded(data_ptr, data_size, encodings);

	// Free allocated memory
	deallocateNodes(parent);

	return 1;
}

int main() {
	uint8_t data_ptr[] = { 0x03, 0x74, 0x04, 0x04, 0x04, 0x35, 0x35, 0x64, 
               			   0x64, 0x64, 0x64, 0x00, 0x00, 0x00, 0x00, 0x00,
               			   0x56, 0x45, 0x56, 0x56, 0x56, 0x09, 0x09, 0x09};

    int data_size = sizeof(data_ptr)/sizeof(*data_ptr);

    int new_size = byte_compress(data_ptr, data_size);

	return 0;
}