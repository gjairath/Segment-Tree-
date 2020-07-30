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
	
	int exp = (int) (ceil(log2(n)));
	*height = 2 * (int) pow(2, exp) - 1;
//	*height = 2 * n;
	int* seg = new int[*height];
//	cout << "Height" << height;
	build_tree(0, arr, seg, 0, n - 1);
	return seg;
}

void debug_printer(int size, int*seg) {
	cout << endl;
	for (int i = 0; i < size; i++) {
		cout << seg[i] << ' ';
	}
	cout << endl;	
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
void modify(int p, int value) {  // set value at position p
  //for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
}

void query(int type, int l, int r, int* st, int size) {

	st[l] = r;
	
	if (l == 0 ) return;
	if (l % 2 == 0) {
		query(1, (l-2)/2, st[l] + st[l-1],st , size);
	} else if (l % 2 != 0) {
	
		query(1, (l-1)/2, st[l] + st[l+1], st, size);
	}
	//if (l == 0) { return;}
}

int main() {

	
//	int n; // no of queries
//	int queries; // no of elements
	
//	cin >> n >> queries;
	
	//int arr[n];
	/*
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		arr[i] = tmp;
	}
	*/
	int arr[8] = {5, 4, 2, 3, 5, 0, 0, 0};
	
	int size = 1;      
	int nn = sizeof(arr) / sizeof(arr[0]);
	int* seg = reserve_memory(arr, nn, &size);	
	
	/*
	
	int result[queries];
	
	
	for (int i = 0; i < queries; i ++) {
		int type;
		int l;
		int r;
		cin >> type >> l >> r;
		if (type == 1) {
			query(1, l, r, seg, size);
		} else if (type == 2) {
			result[i] = query_sum(0, 0, size - 1, l, r, seg);		
		}
	}
	cout << endl;
	for (int i = 0; i < queries; i++) {
		cout << result[i] << endl;
	}
	*/
	
	//cout << size;
	debug_printer(size,seg);
	cout << query_sum(0, 0, nn - 1, 0, 3 - 1, seg) << endl;
	query(1, 1 + 8 - 1, 1, seg, nn);
	debug_printer(size, seg);
	cout << query_sum(0, 0, nn - 1, 0, 3 - 1, seg) << endl; // should be 8

	
//	cout << endl << "Sum :" << query_sum(0, 0, n - 1, 1, 3, seg);
	return 0; 
}
