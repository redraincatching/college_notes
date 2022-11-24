```c
void quick_sort(int arr_a[], int startval, int endval) {
	if ((endval - startval) < 1) {
		return;
	}
	else {
		int k = partition(arr_a, startval, endval);
		//now sort the two sub-arrays
		quick_sort(arr_a, startval, k - 1);  //left partition
		quick_sort(arr_a, k + 1, endval);   //right partition
	}
}

int partition(int arr_a[], int startval, int endval) {
	// better version of partition .. no nested loop
	// pivot at startval as before
	int k;
	int pivot = arr_a[startval];
	int i = startval;

	for (k = startval + 1; k <= endval; k++) { // k keeps incrementing to the end
		if (arr_a[k] <= pivot) {
			i++;   // i only increments when there is a new value to add to the <= portion
			if (i != k) {
				swap(&arr_a[i], &arr_a[k]);
			}
		}
	}
	swap(&arr_a[i], &arr_a[startval]);  // put pivot in correct location i
	return(i);
}

void swap(int* a, int* b) {
	// call with  ... swap(&arr_a[i], &arr_a[j]) to swap the values at positions i and j
	int temp = *a;
	*a = *b;
	*b = temp;
}
```
#c #sorting_algorithm
