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


