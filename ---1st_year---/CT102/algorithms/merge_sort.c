#include "stdafx.h"
#include <stdio.h>
#include "stdlib.h"

void merge (int arr_a[], int lb, int mid, int ub);
void merge_sort (int arr_a[], int lb, int ub);

//merge_sort to sort values in an integer arr_ay arr_a[]
// lb = 0 and ub = size - 1 for the first call
void merge_sort (int arr_a[], int lb, int ub) {

	int mid;

	if (lb < ub) {
    	mid = int((lb + ub) /2);
		merge_sort (arr_a, lb, mid);
		merge_sort (arr_a, mid + 1, ub);
		merge (arr_a, lb, mid, ub);
   }
}


// merge two sorted portions of an integer array arr_a[]:
// portions are lb to mid and mid+1 to ub
void merge (int arr_a[], int lb, int mid, int ub) {

      int i, j, k;
	  int size = ub - lb + 1;
	  int *arr_c;
	  //create arr_c[] to be of size needed for current merge
	  arr_c = (int*) malloc(size * sizeof(int));

	  i = lb;
	  j = mid + 1;
	  k = 0;

	  while (i <= mid && j <= ub) {
		if(arr_a[i] <= arr_a[j]) {
			arr_c[k] = arr_a[i];
			i++;
		}
		else {
			arr_c[k] = arr_a[j];
			j++;
		}
		k++;
	} //end while

	// write out anything left in i part
	while (i <= mid) {
		arr_c[k] = arr_a[i];
		i++;
		k++;
	}
	// write out anything left in j part
	while (j <= ub) {
		arr_c[k] = arr_a[j];
		j++;
		k++;
	}

	//write back from arr_c to arr_a so correct values are in place for next merge
	i = lb;
	k = 0;
	while ( i <= ub ) {
		arr_a[i] = arr_c[k];
		i++;
		k++;
	}
}
