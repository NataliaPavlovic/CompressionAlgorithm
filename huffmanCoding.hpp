#pragma once

#include <vector>
#include "Node.hpp"

void deallocateNodes(Node *);
void createEncodingTable(Node *, std::unordered_map<uint8_t, std::string> &);
Node * buildHuffmanTree(std::vector<Node> &);