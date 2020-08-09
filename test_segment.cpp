#include "segment.cpp"

int main() {
	int arr[8] = {5, -4, 4, 3, -5, 0, 0, 0};
	int nn = sizeof(arr) / sizeof(arr[0]);
	int size = 1;

	Node* seg = reserve_memory_max(arr, nn, &size, isSum);
 	
	int l = 0;
	int r = 7;
		
	
	cout << endl << "The maximum sum from index 0 to index 7 (as per arrays)" << endl;

	cout << max.subSum;
	 	
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
