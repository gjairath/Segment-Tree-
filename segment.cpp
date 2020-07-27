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

void debug_printer(int size, int*seg) {
	for (int i = 0; i < size; i++) {
		cout << seg[i] << ' ';
	}	
}

void query(int type, int l, int r, int* st, int size) {
	if (type == 1) {
		// set index l to r and recalculate the tree.
		st[l] = r;
		
		// Dont remove below line, infinite recursion.
		if (l == 0) { return;}
		query(1, (l-1) / 2, st[l] + st[l+1], st, size);
	}
}

int query_sum(int index, int start, int end, int l, int r, int *st) {
	
	if (start >= l && end <= r) {
		return st[index];
	}
 	
 	if (end < l || start > r) {
 		return 0;	
	}
 	int mid = (start + end) /2;
 	return query_sum(2*index+1, start, mid, l, r ,st) + query_sum(2*index + 2, mid + 1, end, l, r, st);
 	
}

int main() {

	int arr[] = {3, 1, 2, 5, 6, 8, 3, 2};  
    int n = sizeof(arr) / sizeof(arr[0]);
	int size = 1;  
	int* seg = reserve_memory(arr, n, &size);
	

	debug_printer(size, seg);
		
//	query(1, 7, 6, seg, size);
//	cout << endl << "After change" << endl;
	
//	debug_printer(size, seg);
	//	sum = query_sum(0, 0, size - 1, 0, 7, seg);

//	cout << size - 1;
	cout << endl << "Sum :" << query_sum(0, 0, n - 1, 0, 7, seg);
	return 0; 
}
