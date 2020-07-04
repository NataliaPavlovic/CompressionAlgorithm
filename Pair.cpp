#include "Pair.hpp"

Pair Pair::operator + (const Pair &r) {
	Pair temp;
	temp.frequency = frequency + r.frequency;
	temp.data = 0xFF;
	return temp;
}