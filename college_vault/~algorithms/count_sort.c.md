```c
void count_sort(int arr_a[], int size, int maxVal) { // sort an array of integers using count_sort algorithm from 0 to maxVal

	int i, value, count;
	int* freq, * arr_b;
	int freq_size;

	freq_size = maxVal + 1;

	freq = (int*)malloc(freq_size * sizeof(int));   //create freq[]
	arr_b = (int*)malloc(size * sizeof(int));       //create arr_b[] same size as arr_a[]

	// initialise freq[]
	for (i = 0; i < freq_size; i++) {
		freq[i] = 0;
	}

	// count
	for (i = 0; i < size; i++) {
		++freq[arr_a[i]];
	}

	// get <= in freq[]
	for (i = 1; i < freq_size; i++) {
		freq[i] = freq[i] + freq[i - 1];
	}

	// place values from arr_a into arr_b; update freq[]
	for (i = 0; i < size; i++) {
		value = arr_a[i];			//value to sort
		count = freq[value];		//<= freq of value
		arr_b[count - 1] = value; 	//place value in arr_b
		--freq[value];				//decrement freq[]
	} //next value in arr_a

	//write back sorted values to arr_a[] now that sorting finished
	for (i = 0; i < size; i++) {
		arr_a[i] = arr_b[i];
	}
}
```

#c #sorting_algorithm 