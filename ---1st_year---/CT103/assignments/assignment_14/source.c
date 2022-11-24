#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void print_double_array(double* dp, int len);			// reads and prints an array of doubles
void swap_integer_values(int* i1, int* i2);				// swaps the values of the integers these pointers point to
void square_int_array(int* i1, int len);				// squares all of the integers in an array
void print_int_array_backwards(int* arr, int len);		// prints an array of integers backwards
void random_int_array(int* arr, int len, int max);		// prints a random string of ints between 0 and max

int* test_array(int len, int max);						// creates a test array

void main() {
	srand(time(NULL));
	int* array = test_array(10, 10);		// so i can generate a test array
	int empty_array[10];					// for the random_int_array funtion
	double d_array[6] = { 800.18, 192.43, 126.3, 1999, 1265873, 23213 };	// for the print_double_array function

	int x = 6;
	int* xp = &x;
	int y = 7;
	int* yp = &y;			// all for the swap integer values function




	print_double_array(d_array, 6);
	swap_integer_values(xp, yp);
	square_int_array(array, 10);
	print_int_array_backwards(array, 10);
	random_int_array(empty_array, 10, 50);
}


int* test_array(int len, int max) {
	int* arr;
	arr = (int)malloc(len * sizeof(int));

	for (int i = 0; i < len; i++) {
		arr[i] = rand() % max;
	}

	puts("contents of test array:");
	for (int i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	return arr;
}

void print_double_array(double* dp, int len) {
	puts("double array:");
	for (int i = 0; i < len; i++) {
		printf("%.2lf, ", *(dp + i));
	}
	printf("\n");
}

void swap_integer_values(int* i1, int* i2) {
	printf("int 1: %d int 2: %d\n", *i1, *i2);
	int temp = *i1;
	*i1 = *i2;
	*i2 = temp;
	printf("int 1: %d int 2: %d\n", *i1, *i2);
}

void square_int_array(int* i1, int len) {
	int temp = 0;
	puts("squaring array:");
	for (int i = 0; i < len; i++) {
		temp = *(i1 + i) * *(i1 + i);
		printf("%d ", temp);
	}
	printf("\n");
}

void print_int_array_backwards(int* arr, int len) {
	puts("array backwards:");
	for (int i = len - 1; i >= 0; i--) {
		printf("%d ", *(arr + i));
	}
	printf("\n");
}

void random_int_array(int* arr, int len, int max) {
	puts("random ints array:");
	for (int i = 0; i < len; i++) {
		arr[i] = rand() % max;
		printf("%d ", arr[i]);
	}
	printf("\n");
}
