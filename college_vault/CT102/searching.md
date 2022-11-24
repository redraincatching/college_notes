# searching
a fundamental operation in computing
most programming languages have built-in searching functions

## linear search
### outline
#### problem:
in a linear data structure, find the position of a given item, returning the position the item is found or else value -1 if item is not found
#### input:
array arr_a[] with (distinct) values; size of array (size);
#### output:
one integer value indicating the position the item was found at, or -1
#### algorithm idea:
start at index 0, for each position until end of array, check if value at current position is the item required, and output result once finished searching

##### code fragment:
```c
int i;
int out_pos = -1;

for (i = 0; i < size; i++) {    
// could also decrement, (i = size; i >=0; i--)
	if (arr_a[i] == item) {
		position = i;
	}
}
```

issue with this code: when found, continues searching
possible solutions:
- break statement
- change loop check to (i < size && out_pos == -1)

// note: every loop, there are two checks, so slightly slower, but not significant compared to time saved

---
## ordered (sorted) arrays
an array is ordered if the values are in either ascending or descending order
can make searching much more efficient

### faster approach: binary search
#### problem:
in a linear data structure, sorted, no duplicates, find the position of a given item, returning the position found or else val -1 if not found
#### input:
array arr_a[] with data values in sorted order; size of array (size); item to find (item)
#### output:
one integer value indicating not found (-1) or the position item was found at
#### assumptions:
integers in array, sorted ascending
![[binary_search.png]]
#### search idea:
- start at middle index of array
- check if == item
-> if yes, stop and return
-> if no, check whether value is greater than or less than item. hence, check \[0, mid) or (mid, size-1\]
![[binary_search.c]]

##### assumption: data is sorted
- how do we check to see if the array is sorted and in the right order?
- if not sorted, how do we sort it

> #algorithms 