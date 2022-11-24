# counting
many complex systems are built on components that involve counting
e.g. some data mining approaches, search engines, information entropy, etc.

in general, counting involves finding the number of occurrences, or frequency, of one or more items or groups of items in a collection

## counting integers in an array
given an unsorted array arr_a[] of size n, containing positive integers in the range \[0-6], write a function to count the frequency of each integer in the array

### approaches:
- loop through, checking each value at every index, and update count?
- check every value in the same loop, with elifs?

// neither of these are very efficient
- use an integer array (count[]) to keep track of the counts
	- each index holds the frequency of that integer
	- dynamically sized
	 - each location would need to be initialised to 0

```c
int i;
int size;
int arr_a[15] = {// some numbers};
int count[7] = {0,0,0,0,0,0,0};

for (i = 0; i < size; i++) {
    ++count[arr_a[i]];      
    // note: only makes sense if counting integers
}
```
##### what is the size of count[]?
maxvalue + 1

##### how to find max_val
scan through array

##### dynamically sizing the freq array
```c
int* freq;
int freq_size;
freq_size = max_val + 1;
freq = (int*)malloc(freq_size * sizeof(int));
```

##### altering the function:
- if the min_val is much greater than 0?
- to count both positive and negative numbers?

note: see [[count_sort.c]]

> #algorithms 