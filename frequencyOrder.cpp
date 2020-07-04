#include <unordered_map> 
#include <bits/stdc++.h> 
#include "frequencyOrder.hpp"
#include "Pair.hpp"

using namespace std;

void frequencyOrder(vector<Node> &v, uint8_t * data_ptr, int data_size) {
	// Put in unordered map
	unordered_map<uint8_t, int> umap;

	for(int i = 0; i < data_size; i++)
	{
		int key = data_ptr[i];
		if (umap.find(key) == umap.end())
		{
			// If not in umap, add to umap
			umap[key] = 1;
		} 
		else
		{
			// If is in umap
			umap[key]++;
		}
	}

	// Order vector by frequency
	for(auto it = umap.begin(); it != umap.end(); it++)
	{
		v.push_back(Node(Pair(it->first, it->second)));
	}
	sort(v.begin(), v.end()); 
}