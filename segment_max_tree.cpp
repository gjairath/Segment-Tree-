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

int minValue(int x, int y) {
	return (x < y) ? x : y;
}
int maxValue(int x, int y) {
	return (x > y) ? x : y;
}


void debug_printer(int size, int*seg) {
	cout << endl;
	for (int i = 0; i < size; i++) {
		cout << seg[i] << ' ';
	}
	cout << endl;	
}

int build_tree_max (int index, int arr[], int* st, int start, int end) {
//	int* st;
	
	if (start == end) {
		st[index] = arr[start];	
		return arr[start];
	}
	int mid = (start + end) / 2;
	// Once the recursion is complete, we;ve hit the bottom of the tree so
	st[index] = maxValue(build_tree_max(2*index + 1, arr, st, start, mid), build_tree_max(2*index + 2, arr, st, mid + 1, end));
	return st[index];
}

int* reserve_memory_max(int arr[], int n, int* height) {
	// 2 * 2 ^ log2 N - 1 
	
	int exp = (int) (ceil(log2(n)));
	*height = 2 * (int) pow(2, exp) - 1;
	
	int* seg = new int[*height];
	build_tree_max(0, arr, seg, 0, n - 1);
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

int query_max(int index, int start, int end, int *st, int value) {
	
	

	if (st[index] < value) {
		return -1;
	}
	
	if (end - start == 1) {
		return index;
	}
	

 	int mid = (start + end) /2;
 
	int res = query_max(2*index + 1, start, mid, st, value); // go to the left-most subtree
	
	if (res == -1) {
		res = query_max(2*index + 2, mid + 1, end, st, value);
	}
	return res;
}

// Find the minimum in a particular range
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

// Updates value based on index
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

// Find occurances of a specific value
int range_counter(int l, int* seg, int nn, int r, int min) {
	int count = 0;
	for (int i = l + nn - 1; i <= r + nn - 1; i++){
		if (seg[i] == min) {
			count++;
		}
	}
	return count;
}


