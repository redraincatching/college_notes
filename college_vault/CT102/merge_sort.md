# merge sort - a recursive sorting algorithm
an approach to sorting that involves dividing the sorting problem into smaller and smaller sub-problems, sorting those, and then merging those sorted problems back together

developed in 1945 by jon von neumann

### approach:
- instead of the full array, consider two subarrays with size as equal as possible
- keep considering subarrays until size 1 reached
- for each subarray, in sorted order, merge back with next, in sorted order

#### input:
- array arr_a[] of size size, in unsorted order
- lower bound lb, initially 0
- upper bound ub, initially size-1

#### output:
- array arr_a[] of size size, in ascending sorted order

---
### steps:
1) dividing:
continuously reduce array and subarrays until size 1 reached (trivially in sorted order)
2) merging:
continuously merge back into sorted order

#### step 1:
![[merge_sort_dividing.png]]
splitting each at mid until size 1 reached

#### step 2:
![[merge_sort_merging.png]]
merge each back into order

---
## c code
![[mergesort_recursive.c]]

---
## time complexity analysis

![[merge_sort_analysis_1.png]]
![[merge_sort_analysis_2.png]]
![[merge_sort_analysis_3.png]]
![[merge_sort_analysis_4.png]]

![[merge_analysis.png]]
- this merge function takes 17n + 20 steps every time it executes
- mergesort take a function of (n/2)

the whole function would be a function of n, so we can write
f(n) = 2f(n/2) + 17n + 23
_// writing 17 as a constant c, and 23 as a constant cn_

in general,
$f(n) = 2^k*f(\frac{n}{2^k}) + k*cn + const$
![[merge_sort_solve_for_k.png]]
![[merge_sort_solve_for_k_2.png]]

###### complexity
$O(n*\log_2n)$

---
##### notes:
- best and worst case are similar
- fewer comparisons than quicksort
- general purpose sorting technique, unlike countsort
- does not sort in place. requires an array of equal size for temporary holding and a writeback stage. good time complexity, but poor space complexity

> #algorithms #sorting_algorithm 