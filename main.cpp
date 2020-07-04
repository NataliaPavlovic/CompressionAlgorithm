#include <iostream>
#include <vector>
#include "main.hpp"
#include "Pair.hpp"
#include "frequencyOrder.hpp"
#include "Node.hpp"
#include <unordered_map> 

using namespace std;

void deallocateNodes(Node * node) {
	if (!node)
	{
		return;
	}

	deallocateNodes(node->left);
	deallocateNodes(node->right);

	free(node);
}


void outputOriginal(uint8_t * data_ptr, int data_size) {
	cout << "Original Message:" << endl;

	for(int i = 0; i < data_size; i++) {
		cout << std::hex << (unsigned) data_ptr[i] << " ";
	}
	cout << endl << endl;
}

void outputEncoded(uint8_t * data_ptr, int data_size, unordered_map<uint8_t, string> &encodings) {
	cout << "Encoded Message:" << endl;

	for(int i = 0; i < data_size; i++) {
		cout << encodings[data_ptr[i]] << " ";
	}
	cout << endl;
}

void printEncodingTable(unordered_map<uint8_t, string> &encodings) {
	cout << "Encoding Table:" << endl;

	for(auto it = encodings.begin(); it != encodings.end(); it++) {
		cout << std::hex << (unsigned) it->first << "	" << std::dec << it->second << endl;
	}
	cout << endl;
}

void createEncodings(Node * node, unordered_map<uint8_t, string> &encodings) {
	if (!node)
	{
		return;
	}

	// If not internal node, add to encodings table
	if(node->get_data() != 0xFF)
		encodings[node->get_data()] = node->get_encoded_data();

	if(node->left)
		node->left->encode(node->get_encoded_data() + "0");
	createEncodings(node->left, encodings);
	if(node->right)
		node->right->encode(node->get_encoded_data() + "1");
	createEncodings(node->right, encodings);
}

Node * buildHuffmanTree(vector<Node> &v) {
	Node * ninternal, *nleft, *nright;
	// Add case where vector length is 1
	while(v.size() > 1)
	{
		if(!v[0].node)
			nleft = new Node(v[0]);
		else
			nleft = v[0].node;
		if(!v[1].node)
			nright = new Node (v[1]);
		else
			nright = v[1].node;

		ninternal = new Node();
		*ninternal = *nleft + *nright;
		ninternal->left = nleft;
		ninternal->right = nright;
		ninternal->node = ninternal;
		v.erase(v.begin()); // erase first element
		v.erase(v.begin()); // erase second element
		v.push_back(*ninternal);
		sort(v.begin(), v.end());
	}
	return (ninternal);
}

int byte_compress(uint8_t * data_ptr, int data_size) {

	vector<Node> v;
	frequencyOrder(v, data_ptr, data_size);

	// Build Huffman tree
	Node * parent = buildHuffmanTree(v);

	// Fill in encodings in tree
	parent->encode("0");
	unordered_map<uint8_t, string> encodings;
	createEncodings(parent, encodings);

	// Output encodings table
	printEncodingTable(encodings);

	outputOriginal(data_ptr, data_size);
	// Output encoded message
	outputEncoded(data_ptr, data_size, encodings);

	// Free dynamic memory
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