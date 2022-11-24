# sorting algorithms
algorithms that put items in the correct order
most commonly, based on numeric value

many different types
- bubble sort
- merge sort
- insertion sort
- quick sort
- selection sort
- bogosort

## [[bubble_sort.c|bubble sort]]
comparing elements to make larger numbers move higher in the array
(they "float" up to the top)
not the most efficient, but that's okay

### approach
first element, check if larger than second, if so, swap
next element, check if larger than following, if so, swap
continue until reach last element
-> repeat, starting at one, and ending at penultimate spot

### structure
outer for loop for loops
&nbsp;&nbsp;&nbsp;&nbsp;inner for loop for size comparisons

array to iterate through

### pseudocode (or python, not much difference)
1. initialise array, indices
2. for p = 0 up to array length
3. for i = 0 up to array length - p-1
4. if (item at position i > item at position i+1)
5. swap



> #c #programming #sorting_algorithm 
> [[algorithmic_analysis]]