#pragma once

#include <bits/stdc++.h> 

using namespace std;

class Pair
{
	uint8_t data;
	int frequency;
	int compare(const Pair &) const;

	public:	
		Pair() {data = 0xFF; frequency = 0;}
		Pair(const uint8_t &d, const int &f) {data = d; frequency = f;}
		uint8_t get_data() const {return data;}
		int get_frequency() const {return frequency;}
		Pair operator + (const Pair &);
};