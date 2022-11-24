void insertion_sort (int* arr, int size) {
    int i, j, curr;
    for (i = 1; i < size; i++) {
        curr = arr[i];
        for (j = i - 1; j >= 0 && curr < arr[j]; j--) {
                arr[j+1] = arr[j];
                // making room
        }
        if (i != j + 1) {   // if not already at the correct position
            arr[j+1] = curr;
        }
    }
}
