#include <cstdio>
#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector
#include <cmath>       /* sqrt */
#include <numeric>      

using namespace std;

typedef long long int ll;

int build_tree (int index, int arr[], int* st, int start, int end) {
//	int* st;
	
	if (start == end) {
		st[index] = arr[start];	
		return arr[start];
	}
	int mid = (start + end) / 2;
	// Once the recursion is complete, we;ve hit the bottom of the tree so
	st[index] = build_tree(2*index + 1, arr, st, start, mid) + build_tree(2*index + 2, arr, st, mid + 1, end);
}

int* reserve_memory(int arr[], int n, int* height) {
	// 2 * 2 ^ log2 N - 1 
	
	int exp = (int) log2(n);
	*height = 2 * pow(2, exp) - 1;
	int* seg = new int[*height];
	build_tree(0, arr, seg, 0, n - 1);
	return seg;
}

int main() {

	int arr[] = {3, 1, 2, 5, 6, 8, 3, 2};  
    int n = sizeof(arr) / sizeof(arr[0]);
	int size = 1;  
	int* seg = reserve_memory(arr, n, &size);
	
	cout << size << endl;
	for (int i = 0; i < 15; i++) {
		cout << seg[i] << ' ';
	}
	
	return 0; 
}
