void selection_sort(int arr[], int size) {
    int min, temp, i, j;
    for (i = 0; i < size; i++) {
        min = i;
        for (j = min + 1; j < size; j++) {
            if (arr[min] > arr[j]) {
                min = j;
            }
        }

        if (i != min) {
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}
