#include <stdio.h>
#include <time.h>
#define SIZE 5000

int unsorted_0[SIZE];
int sorted_0[SIZE];


void into_array(int* arr, int size, FILE* fptr);	// read file values into array
int* copy_array(int* source, int size);				// make a copy of the array
void bubble_sort(int* arr, int size);
void insertion_sort(int* arr, int size);
void selection_sort(int* arr, int size);

void main() {
	FILE* fptr0;
	FILE* fptr1;

	fopen_s(&fptr0, "C:\\Users\\eidhn\\Desktop\\college\\_misc\\5000_ints.txt", "r");
	fopen_s(&fptr1, "C:\\Users\\eidhn\\Desktop\\college\\_misc\\5000_sorted_ints.txt", "r");

	into_array(unsorted_0, SIZE, fptr0);
	int* unsorted_1 = copy_array(unsorted_0, SIZE);
	int* unsorted_2 = copy_array(unsorted_0, SIZE);
	into_array(sorted_0, SIZE, fptr1);
	int* sorted_1 = copy_array(sorted_0, SIZE);
	int* sorted_2 = copy_array(sorted_0, SIZE);


	// unsorted first
	puts("----------\nunsorted integers:\n----------\n");
	bubble_sort(unsorted_0, SIZE);
	insertion_sort(unsorted_1, SIZE);
	selection_sort(unsorted_2, SIZE);

	// now sorted
	puts("----------\nsorted integers:\n----------\n");
	bubble_sort(sorted_0, SIZE);
	insertion_sort(sorted_1, SIZE);
	selection_sort(sorted_2, SIZE);
}

void into_array(int* arr, int size, FILE* fptr) {		// real simple
	char line[50];
	int i = 0;

	while (!feof(fptr)) {
		fscanf_s(fptr, "%d", &arr[i]);
		i++;
	}
	fclose(fptr);
}

int* copy_array(int* source, int size) {	// necessary because c's buffer is weird with files
	int* destination;
	destination = (int)malloc(size * sizeof(int));
	for (int i = 0; i < size; i++) {
		destination[i] = source[i];
	}
	return destination;
}

void bubble_sort(int* arr, int size) {
	clock_t start, end;
	start = clock();
	double time_taken;
	int comparisons = 0, swaps = 0;

	int i, k, temp;
	for (k = 0; k < size; k++) {
		for (i = 0; i < size - 1 - k; i++) {
			comparisons++;
			if (arr[i] > arr[i + 1]) {
				// out of order so swap
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				swaps++;
			}
		}
	}

	end = clock();
	time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
	printf("bubble sort finished.\nno. comparisons: %d\nno. swaps: %d\ntime taken: %lf seconds\n\n", comparisons, swaps, time_taken);
}

void insertion_sort(int* arr, int size) {
	clock_t start, end;
	start = clock();
	double time_taken;
	int comparisons = 0, swaps = 0;

	int i, j, curr;
	for (i = 1; i < size; i++) {
		curr = arr[i];
		for (j = i - 1; j >= 0 && curr < arr[j]; j--) {
			swaps++;
			comparisons++;
			arr[j + 1] = arr[j];
			// making room
		}
		comparisons++;
		if (i != j + 1) {   // if not already at the correct position
			arr[j + 1] = curr;
			swaps++;
		}
	}

	end = clock();
	time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
	printf("insertion sort finished.\nno. comparisons: %d\nno. swaps: %d\ntime taken: %lf seconds\n\n", comparisons, swaps, time_taken);
}

void selection_sort(int* arr, int size) {
	clock_t start, end;
	start = clock();
	double time_taken;
	int comparisons = 0, swaps = 0;

	int min, temp;
	for (int i = 0; i < size; i++) {
		min = i;
		for (int j = min + 1; j < size; j++) {
			comparisons++;
			if (arr[min] > arr[j]) {
				min = j;
			}
		}
		comparisons++;
		if (i != min) {
			swaps++;
			temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
		}
	}


	end = clock();
	time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
	printf("selection sort finished.\nno. comparisons: %d\nno. swaps: %d\ntime taken: %lf seconds\n\n", comparisons, swaps, time_taken);
}
