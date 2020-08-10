#include "segment_max_tree.cpp"

int main() {
	int arr[16] = {2,4, 6, 8, 10, 12, 14, 16 , 18, 20, 1, 2, 1,2 ,2, 3};
	int nn = sizeof(arr) / sizeof(arr[0]);
	int size = 1;

	int* seg = reserve_memory_max(arr, nn, &size);
 	
	int l = 0;
	int r = 7;
		
	debug_printer(size, seg);	

	int find_value = 5;
	int result = query_max(0, 0, nn - 1, seg, find_value);
	cout << endl << result << ' '<< seg[result];
	
	int find_value_2 = 4;
	int desired_index = 2;
	

	int result_2 = query_max_2(0, 0, nn, desired_index, seg, find_value_2);
	
	cout << endl << result_2 << ' ' << seg[result_2];
	
	return 0; 
}
