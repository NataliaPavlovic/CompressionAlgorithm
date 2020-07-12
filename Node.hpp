#pragma once

#include <cstdint>
#include <string>

class Node{
	uint8_t data;
	int frequency;
	std::string encoded_data;
	int compare(const Node &) const;

	public:
		Node * left;
		Node * right;
		Node * internal_node;
		Node();
		Node(const uint8_t &d, const int &f);
		Node(const Node &);
		Node operator + (Node &);
		int get_frequency() const {return frequency;}
		uint8_t get_data() const {return data;}
		void encode(const std::string &s) {encoded_data = s;}
		std::string get_encoded_data() {return encoded_data;}
		bool operator < (const Node & r) {return(compare(r)<0);}
		bool operator > (const Node & r) {return(compare(r)>0);}
		bool operator <= (const Node & r) {return(compare(r)<=0);}
		bool operator >= (const Node & r) {return(compare(r)>=0);}
		bool operator == (const Node & r) {return(!compare(r));}
};