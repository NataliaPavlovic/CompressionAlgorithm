#include "huffmanCoding.hpp"
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

void createEncodingTable(Node * node, unordered_map<uint8_t, string> &encodings) {
	if (!node)
	{
		return;
	}

	// If not internal node, add to encodings table
	if(node->get_data() != 0xFF)
		encodings[node->get_data()] = node->get_encoded_data();

	if(node->left)
		node->left->encode(node->get_encoded_data() + "0");
	createEncodingTable(node->left, encodings);
	if(node->right)
		node->right->encode(node->get_encoded_data() + "1");
	createEncodingTable(node->right, encodings);
}

Node * buildHuffmanTree(vector<Node> &v) {
	Node * ninternal, *nleft, *nright;
	// Add case where vector length is 1
	while(v.size() > 1)
	{
		if(!v[0].internal_node)
			nleft = new Node(v[0]);
		else
			nleft = v[0].internal_node;
		if(!v[1].internal_node)
			nright = new Node (v[1]);
		else
			nright = v[1].internal_node;

		ninternal = new Node();
		*ninternal = *nleft + *nright;
		ninternal->left = nleft;
		ninternal->right = nright;
		ninternal->internal_node = ninternal;
		v.erase(v.begin()); // erase first element
		v.erase(v.begin()); // erase second element
		v.push_back(*ninternal);
		sort(v.begin(), v.end());
	}
	return (ninternal);
}