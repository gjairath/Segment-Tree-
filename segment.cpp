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



Node merge_nodes(Node left_child, Node right_child) {
	
	Node parent_node;
	
	parent_node.subSum = max({left_child.subSum, right_child.subSum, left_child.suffixSum + right_child.prefixSum});
	parent_node.prefixSum = max(left_child.prefixSum, left_child.totalSum + right_child.prefixSum);
	parent_node.suffixSum = max(left_child.suffixSum + right_child.totalSum, right_child.totalSum);
	parent_node.totalSum = left_child.totalSum + right_child.totalSum;
	
	return parent_node;
}


void build_tree_sum (int index, int arr[], Node* st, int start, int end) {
//	int* st;
	
	if (start == end) {
		st[index].subSum = arr[start];	
		st[index].prefixSum = arr[start];	
		st[index].suffixSum = arr[start];	
		st[index].totalSum = arr[start];	
		
		return;
	}
	int mid = (start + end) / 2;
	// Once the recursion is complete, we;ve hit the bottom of the tree so
	build_tree_sum(2*index + 1, arr, st, start, mid);
	build_tree_sum(2*index + 2, arr, st, mid + 1, end);
	
	st[index] = merge_nodes(st[2*index +1], st[2*index+2]);
}


Node* reserve_memory(int arr[], int n, int* height, bool isSum) {
	// 2 * 2 ^ log2 N - 1 
	
	int exp = (int) (ceil(log2(n)));
	*height = 2 * (int) pow(2, exp) - 1;
	if (isSum) {
		Node* seg = new Node[*height];
		build_tree_sum(0, arr, seg, 0, n - 1);
		return seg;
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




// Find the max sum on a subsegment
Node query_max_sums(int index, int start, int end, int l, int r, Node *st) {
	if (start >= l && end <= r) {
		return st[index];
	}
	if (end < l || start > r) {
 		Node null;
		return null;	
	}
 	int mid = (start + end) /2;
 	//cout << mid;
	
	Node left = query_max_sums(2*index+1, start, mid, l, r ,st);
	Node right = query_max_sums(2*index + 2, mid + 1, end, l, r, st);
	
	Node result;
	result = merge_nodes(left, right);
	return result;
}


