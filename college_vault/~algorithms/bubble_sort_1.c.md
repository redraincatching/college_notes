```c
void bubble_sort (int* arr_a, int size) {
    int i, k, temp;
    for (k = 0; k < size; k++) {
        for (i = 0; i < size - 1 - k; i++) {
            if (arr_a[i] > arr_a[i+1]){
                // out of order so swap
                temp = arr_a[i];
                arr_a[i] = arr_a[i+1];
                arr_a[i+1] = temp;
            }
        }
    }
}
```
#c #sorting_algorithm 