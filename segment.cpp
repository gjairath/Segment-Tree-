#include <cstdio>
#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector
#include <cmath>       /* sqrt */
#include <numeric>      

using namespace std;

typedef long long int ll;

int* build_tree (int index, int arr[], int start, int end) {
	int* st;
	
	if (start == end) {
		st[index] = arr[start];	
		return;
	}
	int mid = (start + end) / 2;
	build(2*index + 1, arr, start, mid);
	build(2*index + 2, arr, mid + 1, end);
	// Once the recursion is complete, we;ve hit the bottom of the tree so
	st[index] = (st[2*index + 1] + st[2*index +2]);
	
}

int main() {
	
	int arr[4] = {3, 1, 2, 5, 6, 8, 3, 2};
	
	int sts[]
	
	
	return 0; 
}
