#include "segment_inversions.cpp"



int main() {
//	int arr[5] = {20, 40, 1, 2, 5};
	int arr[5] = {4, 1, 3, 5, 2};
	int nn = sizeof(arr) / sizeof(arr[0]);


	int max = *max_element(arr, arr + nn);
	
	int* seg = new int[6 * max];
	memset(seg, 0, 6*max);
	
	
	return 0; 
}
