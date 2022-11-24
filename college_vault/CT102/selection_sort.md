# selection sort
searches the entire array and selects the largest/smallest element, and puts it at the corresponding index

then, checks for next largest/smallest element (ignoring already sorted index)
-> repeat until sorted

## algorithm outline
### input:
array of integers with give size
### output:
array with data sorted in increasing order
### approach (for finding smallest):
![[selection_sort.c]]

note: also $O(n^2)$
// see [[algorithmic_analysis]]

> #algorithms 