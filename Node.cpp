#include "Node.hpp"

using namespace std;

Node::Node() {
	data = 0xFF;
	frequency = 0;
	encoded_data = "";
	left = nullptr;
	right = nullptr;
	internal_node = nullptr;
}

Node::Node(const uint8_t &d, const int &f){
	data = d; 
	frequency = f;
	encoded_data = "";
	left = nullptr;
	right = nullptr;
	internal_node = nullptr;
}

Node::Node(const Node & param){
	data = param.data;
	frequency = param.frequency;
	encoded_data = param.encoded_data;
	left = param.left;
	right = param.right;
	internal_node = param.internal_node;
}

Node Node::operator + (Node & r) {
	Node temp;
	temp.frequency = frequency + r.frequency;
	temp.data = 0xFF;
	temp.left = this;
	temp.right = &r;
	return temp;
}

int Node::compare(const Node &r) const
{
	int lf = this->get_frequency();
	int rf = r.get_frequency();

	// if lf < rf, return negative
	// if lf > rf, return positive
	// if lf == rf, return 0
	return (lf-rf);
}
