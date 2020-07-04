#pragma once

#include <unordered_map> 
#include <bits/stdc++.h> 
#include <string>

void outputOriginal(uint8_t *, int);
void outputEncoded(uint8_t *, int, std::unordered_map<uint8_t, std::string> &);
void outputEncodingTable(std::unordered_map<uint8_t, std::string> &);