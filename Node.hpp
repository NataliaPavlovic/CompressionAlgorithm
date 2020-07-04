#pragma once
#include <string>
#include "Pair.hpp"

using namespace std;

class Node{
	Pair p;
	string encoded_data;
	int compare(const Node &) const;

	public:
		Node * left;
		Node * right;
		Node * node;
		Node();
		Node(const Pair &);
		Node(const Node &);
		Node operator + (Node &);
		int get_frequency() const {return p.get_frequency();}
		uint8_t get_data() const {return p.get_data();}
		Pair get_pair() {return p;}
		void encode(const string &s) {encoded_data = s;}
		string get_encoded_data() {return encoded_data;}
		bool operator < (const Node & r) {return(compare(r)<0);}
		bool operator > (const Node & r) {return(compare(r)>0);}
		bool operator <= (const Node & r) {return(compare(r)<=0);}
		bool operator >= (const Node & r) {return(compare(r)>=0);}
		bool operator == (const Node & r) {return(!compare(r));}
};