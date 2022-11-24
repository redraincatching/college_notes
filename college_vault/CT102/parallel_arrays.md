# parallel arrays
- multiple arrays of the same size used to store records
- a separate array, with data of the same type, is used for each field of the record
- each array must have the same size, but can have different data types
- values for a record are located at the same index in each array

## steps when creating parallel arrays
declare each array, specifying names, datatype, and size
- the size of all arrays should be the same
- data types can be different

populate the arrays in parallel, i.e. enter data in arr_1\[i] and arr_2\[i] at the same time, then i+1 for both, and so on

---
## merging sorted arrays
### inputs:
- sorted array arr_a[] of size size_a, unique values
- sorted array arr_b[] of size size_b, unique values
### outputs:
- sorted array arr_c[] of size size_c, containing data from arr_a[] and arr_b[], unique values
### assumptions:
duplicates between arr_a[] and arr_b[] are discarded, i.e. each value is only present once in arr_c[]

### steps:
- while not at the end of arr_a[] and arr_b[], compare arr_a\[i] and arr_b\[j], putting the smaller into arr_c\[k]
- if at the end of one array, there are values left in the other, append arr_c[] with the remaining values in the other array
#### sample code
```c
void merge (int arr_a[], int size_a, int arr_b[], int size_b) {
    int i = 0, j = 0, k = 0;
    int size_c;

    // setting size of arr_c[] dynamically
    size_c = size_a + size_b;

    // declare arr_c of size size_c using malloc()
    int *arr_c;
    arr_c = (int) malloc(size_c * sizeof(int));
    // basically, arr_c now points to a space the size of size_c * data_size_in_bytes

    while (i < size_a && j < size_b) {
        if (arr_a[i] < arr_b[j]) {
            arr_c[k] = arr_a[i];
            i++
        }
        else if (arr_b[j] > arr_a[i]) {
            arr_c[k] = arr_b[j];
            j++;
        }
        else {  // if the two values are equal
            arr_c[k] = arr_a[i];
            i++;
            j++;
        }
        k++;
    }
    if (i == size_a) {  // all of arr_a was written
        while(j < size_b) {
            arr_c[k] = arr_b[j];
            k++;
            j++;
        }
    }
    else if (j == size_b) {  // all of arr_b was written
        while(i < size_a) {
            arr_c[k] = arr_a[i];
            k++;
            i++;
        }
    }
    size_c = k; // correct size of arr_c
}
```

> #algorithms 