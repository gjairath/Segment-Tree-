#include <cstdio>
#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector
#include <cmath>       /* sqrt */
#include <numeric>      
#include <bits/stdc++.h> 

#include "Node.h"

using namespace std;

typedef long long int ll;

void debug_printer(int size, int*seg) {
	cout << endl;
	for (int i = 0; i < size; i++) {
		cout << seg[i] << ' ';
	}
	cout << endl;	
}

void update(int* seg, int index_up, int nn) {
	
	int c = 0;
	
	if (seg[index_up] == 0) {
		for (int i = index_up; i < nn; i++) {
			c += seg[i];
		}
		if (c == 0) {
			c = 1;
		}
	seg[index_up] = c;
	return;
	}
}

int* reserve_memory_max(int arr[], int n) {
	// 2 * 2 ^ log2 N - 1 

	
	int* seg = new int[n];
	for (int i = 0; i < n; i ++) {
		seg[i] = 0;
	}
	return seg;
	
}
