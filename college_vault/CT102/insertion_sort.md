# insertion sort
scans elements in a list, inserting each element into its proper position
## steps:
- consider the first 2 elements, and check if sorted
-> if not, sort relative to each other
- consider the third element
-> if out of order, sort the first 3 elements relative to each other
- continue, at each stage considering each new element, and inserting it into the correct position in the previously sorted sub-array

## algorithm outline
### input:
array arr[] of integers of given size
### output:
array sorted in increasing order
### approach:
- start at position i=1, and let curr = arr\[i\]
- compare curr with arr\[i-1\]
- if out of order, find correct position in previously sorted sub-array
- then insert, "making room" by moving all following values up by one

_// note: must stop sorting at arr\[0\], otherwise oob error_

![[insertion_sort.c]]

> #algorithms 