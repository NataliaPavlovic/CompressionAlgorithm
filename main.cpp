#include <iostream>
#include <vector>
#include "main.hpp"
#include "Pair.hpp"
#include "frequencyOrder.hpp"
#include "Node.hpp"

using namespace std;

void encode(Node * parent) {
	cout << parent->get_frequency() << endl;
	if (!parent)
	{
		return;
	}
	if(parent->left) {
		parent->left->encode(parent->get_encoded_data() + "0");
		encode(parent->left);
	} 
	if(parent->right) {
		parent->right->encode(parent->get_encoded_data() + "1");
		encode(parent->right);
	}
}

Node * buildHuffmanTree(vector<Node> &v) {
	Node * ninternal, *nleft, *nright;
	// Add case where vector length is 1
	// while(v.size() > 1)
	// {
	// 	nleft = new Node(v[0]);
	// 	nright = new Node (v[1]);
	// 	ninternal = new Node();
	// 	*ninternal = *nleft + *nright;
	// 	ninternal->left = nleft;
	// 	ninternal->right = nright;
	// 	v.erase(v.begin()); // erase first element
	// 	v.erase(v.begin()); // erase second element
	// 	v.push_back(ninternal->get_pair());
	// 	sort(v.begin(), v.end());

	// 	cout << "************************" << endl;

	// 	for(auto it = v.begin(); it != v.end(); it++)
	// 	{
	// 		cout << hex << (unsigned) it->get_data() << "		" << dec << it->get_frequency() << endl;
	// 	}
	// }
	return (ninternal);
}

int byte_compress(uint8_t * data_ptr, int data_size) {

	vector<Node> v;
	frequencyOrder(v, data_ptr, data_size);

	cout << "Data:		Frequency:" << endl;
	for(auto it = v.begin(); it != v.end(); it++)
	{
		cout << std::hex << (unsigned) it->get_data() << "		" << it->get_frequency() << endl;
	}

	// Build Huffman tree
	Node * parent = buildHuffmanTree(v);
	parent->encode("0");
	encode(parent);

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