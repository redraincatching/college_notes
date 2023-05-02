# operations on matrices
## matrix multiplication
by a scalar
-> every element times that scalar
by another matrix
-> matrix c is the r x c product ab of the r x n matrix a with the n x c matrix b
each element $c_{ij}$ of the matrix c is the product of the element of the ith row of a times the jth column of b

## element-wise operations
applying an operation on an element by element basis
usage: dot operator
\* is matrix multiplication
.* is element-wise operation
-> this would essentialy iterate through the two operand matrices and apply the operation between the ith element of both matrices

## logical vectors and arrays
performing a logical comparison on a vector, e.g. v > 3, performs that comparison element-wise on the vector, and stores the results in a logical vector of the same size
this logical vector can be used to filter the original vector

e.g.
```matlab
x = [1 2 3 4 5]
y = x > 3
% y = [0 0 0 1 1]

x(y)
% x = [4 5]

x(x>mean(x))
```

> #matlab #modelling 