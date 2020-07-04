#include <iostream>
#include "output.hpp"

using namespace std;

void outputOriginal(uint8_t * data_ptr, int data_size) {
	cout << "Original Message:" << endl;

	for(int i = 0; i < data_size; i++) {
		cout << hex << (unsigned) data_ptr[i] << " ";
	}
	cout << endl << endl;
}

void outputEncoded(uint8_t * data_ptr, int data_size, unordered_map<uint8_t, string> &encodings) {
	cout << "Encoded Message:" << endl;

	int encoded_size = 0;

	for(int i = 0; i < data_size; i++) {
		cout << encodings[data_ptr[i]] << " ";
		encoded_size += (encodings[data_ptr[i]]).size();
	}
	cout << endl << endl;
	cout << "Original Size:		" << dec << data_size * 8 << " bits" << endl;
	cout << "Encoded Size:		" << dec << encoded_size << " bits" << endl;
	cout << "Compressions Ratio:	" << fixed << static_cast<double>(data_size * 8)/(encoded_size) << endl;
	double space_savings = 1 - static_cast<double>(encoded_size)/(data_size * 8);
	int percent = (space_savings * 100);
	cout << "Space Savings: 		" << dec << percent << "%" << endl;
}

void outputEncodingTable(unordered_map<uint8_t, string> &encodings) {
	cout << "Encoding Table:" << endl;

	for(auto it = encodings.begin(); it != encodings.end(); it++) {
		cout << hex << (unsigned) it->first << "	" << dec << it->second << endl;
	}
	cout << endl;
}