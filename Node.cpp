#include "Node.hpp"
#include "Pair.hpp"

Node::Node() {
	encoded_data = "";
	left = nullptr;
	right = nullptr;
}

Node::Node(const Pair & param){
	p = param; // Default copy is okay
	encoded_data = "";
	left = nullptr;
	right = nullptr;
}

Node::Node(const Node & param){
	p = param.p; // Default copy is okay
	encoded_data = "";
	left = nullptr;
	right = nullptr;
}

Node Node::operator + (Node & r) {
	Node temp;
	temp.p = p + r.p;
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
