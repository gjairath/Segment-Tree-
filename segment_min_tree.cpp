

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


