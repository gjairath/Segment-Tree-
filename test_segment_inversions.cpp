#include "segment_inversions.cpp"

static int find_index(int item, int arr[], int nn) {
	
	for (int i = 0; i < nn; i++){
		if (item == arr[i]) {
			return i;
		}
	}
}

int main() {
//	int arr[5] = {20, 40, 1, 2, 5};
	int arr[5] = {4, 1, 3, 5, 2};
	int nn = sizeof(arr) / sizeof(arr[0]);

	int* seg = reserve_memory_max(arr, nn);
 	
	debug_printer(nn, seg);	

	int arr2[5];
	
	for (int i = 0; i < nn; i++){
		arr2[i] = arr[i];
	}	
	sort(arr2, arr2 + nn);
	
	
	for (int i = 0; i < nn; i++) {
		
		update(seg, find_index(arr[i], arr2, nn), nn);
	}
	
	cout << endl;
	debug_printer(nn, seg);
	
	return 0; 
}
