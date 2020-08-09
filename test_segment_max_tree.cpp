#include "segment_max_tree.cpp"

int main() {
	int arr[8] = {3, 2, 1, 3, 2, 6, 4, 8};
	int nn = sizeof(arr) / sizeof(arr[0]);
	int size = 1;

	int* seg = reserve_memory_max(arr, nn, &size);
 	
	int l = 0;
	int r = 7;
		
	debug_printer(size, seg);	

	int find_value = 5;

	
	int result = query_max(0, 0, nn - 1, seg, find_value);
	
	cout << endl << result << ' '<< seg[result];
	
	
	
	return 0; 
}
