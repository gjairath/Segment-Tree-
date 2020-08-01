#include <cstdio>
#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector
#include <cmath>       /* sqrt */
#include <numeric>      
#include <bits/stdc++.h> 

	

using namespace std;

typedef long long int ll;


int minValue(int x, int y) {
	return (x < y) ? x : y;
}

void debug_printer(int size, int*seg) {
	cout << endl;
	for (int i = 0; i < size; i++) {
		cout << seg[i] << ' ';
	}
	cout << endl;	
}


int build_tree_sum (int index, int arr[], int* st, int start, int end) {
//	int* st;
	
	if (start == end) {
		st[index] = arr[start];	
		return arr[start];
	}
	int mid = (start + end) / 2;
	// Once the recursion is complete, we;ve hit the bottom of the tree so
	st[index] =  ( build_tree_sum(2*index + 1, arr, st, start, mid) + build_tree_sum(2*index + 2, arr, st, mid + 1, end) );
}

int build_tree_min (int index, int arr[], int* st, int start, int end) {
//	int* st;
	
	if (start == end) {
		st[index] = arr[start];	
		return arr[start];
	}
	int mid = (start + end) / 2;
	// Once the recursion is complete, we;ve hit the bottom of the tree so
	st[index] = minValue(build_tree_min(2*index + 1, arr, st, start, mid), build_tree_min(2*index + 2, arr, st, mid + 1, end));
	return st[index];
}

int* reserve_memory(int arr[], int n, int* height) {
	// 2 * 2 ^ log2 N - 1 
	
	int exp = (int) (ceil(log2(n)));
	*height = 2 * (int) pow(2, exp) - 1;
//	*height = 2 * n;
	int* seg = new int[*height];
//	cout << "Height" << height;
	build_tree_min(0, arr, seg, 0, n - 1);
	return seg;
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

int query_no_mins(int index, int start, int end, int l, int r, int *st) {
	
	if (start >= l && end <= r) {
		return st[index];
	}
	if (end < l || start > r) {
 		return INT_MAX;	
	}
 	int mid = (start + end) /2;
 	//cout << mid;
	
	return minValue( query_no_mins(2*index+1, start, mid, l, r ,st), query_no_mins(2*index + 2, mid + 1, end, l, r, st) );
}

// Updates value 
void query(int type, int l, int r, int* st, int size) {

	st[l] = r;
	//cout << (0 + 7) / 2;
	if (l == 0 ) return;
	if (l % 2 == 0) {
		query(1, (l-2)/2, st[l] + st[l-1],st , size);
	} else if (l % 2 != 0) {
	
		query(1, (l-1)/2, st[l] + st[l+1], st, size);
	}
	//if (l == 0) { return;}
}

int main() {
	int arr[8] = {3,3,1,5,2,10000,10000,10000};
	int nn = sizeof(arr) / sizeof(arr[0]);
	int size = 1;
	int* seg = reserve_memory(arr, nn, &size);
	debug_printer(size, seg);
	
	int l = 0;
	int r = 1;
	
	int min = query_no_mins(0, 0, nn - 1, l, r, seg); // l and r are according to arrays
	
	cout << endl << "The minimum from index 1 to index 3 (as per arrays)" << endl;
	int count = 0;
	for (int i = l + nn - 1; i <= r + nn - 1; i++){
		if (seg[i] == min) {
			count++;
		}
	}
	cout << min << " Occurs: " << count;
 	
	//  UNCOMMENT BELOW FOR USER INPUT
	/*
	int n; // no of elemnets
	int queries; // 
	
	cin >> n >> queries;
	
	int next = pow(2, ceil(log(n)/log(2))); // Find nearest power 2 for the sexy tree

	int arr[next] = {0};

	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		arr[i] = tmp;
	}
	
	
	int size = 1;      
	int nn = sizeof(arr) / sizeof(arr[0]);
	int* seg = reserve_memory(arr, nn, &size);	
	
	
	int result[queries] = {-1};
	fill_n(result, queries, -1);

	
	for (int i = 0; i < queries; i ++) {
		int type;
		int l;
		int r;
		cin >> type >> l >> r;
		if (type == 1) {
			query(1, l + next - 1, r, seg, nn);
			//debug_printer(size, seg);
		} else if (type == 2) {
			result[i] = query_no_mins(0, 0, nn - 1, l, r - 1, seg);		
			//debug_printer(size, seg);

		}
	}
	cout << endl;
	for (int i = 0; i < queries; i++) {
		if (result[i] != -1) {
		
			cout << result[i] << endl;
		}
	}	
	*/
	return 0; 
}
