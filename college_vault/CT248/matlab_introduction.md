# matlab
high-level language
MATrix LABoratory
designed to make matrix computations particularly easy
used for 
- numerical computation
- data analysis
- algorithm development and programming
- application development and deployment

## variables
loosely typed
only letters, digits, and underscores
must start with a letter
case sensitive
the semi-colon at the end is actually optional, but it prevents the value from being displayed
syntax
\<name\> = \<value\>;

## the matlab workspace
all the variables created during a session remain in the workspace until you clear them
the command who lists all the names in the workspace
the commands whos also lists the size of them
the ide holds a visual representation of this

// note: the function ans returns the last value evaluated and not assigned to a variable

## statements
frequently of the form \<variable\> = \<expression\>
statements that are too long for a line can be extended by an ellipsis of at least three dots

## i/o
```matlab
name = input ('enter your name: ', 's');
fprintf("your name is %s\n", name);
```
// can also use disp()

> general process - IPO
> input -> process -> output

## repetition
for loop structure in matlab
```matlab
for index = j:k
	statements;
end
```

or
```matlab
for index = j:m:k
	statements;
end
```

j:k is a vector with elements $j, j+1, j_2, ..., k$
j:m:k is a vector with elemengts $j, j+m, j+2m, ...$ (does not exceed k)
index must be a variable

## syntax
### comments
```matlab
% this is a line comment
%{ 
this is a block comment
%}
```

### logical operators
all usual except ~= is not equal

### if statements
#### one-line
if condition; statements; end;
#### if-else
```matlab
if condition
	statements;
elseif condition1
	statements;
else
	statements;
end
```

## initialising vectors
```matlab
v = [1 2 3 4 5]
```
% must be separated by commas or space
% some operations exist such as sum(v), mean(v), or a slice, performed with $v(i_0:i_1)$
v = j:m:k
j = start
m = step
k = end/max

## transposing vectors
v' changes v from a row to a column

## matrices
```matlab
m = [1 2 3; 4 5 6]
% can also be transposed with m'
```

## extracting sections of a matrix
```matlab
m(1,2);     % element (1,2)
m(:,2);     % column 2
```

## matrix functions
- eye
	identify matrix
- linspace
	vector with linearly spaced elements
- ones
	matrix of ones
- rand
	uniformly distributed random numbers and arrays
- randn
	normally distributed random numbers and arrays
- zeros
	matrix of zeros
- det
	determinant
 - eig
	eigenvalues and eigenvectors
 - expm
	matrix exponential
- inv
	matrix inverse
- trace
	sum of diagonal elements

> #matlab #modelling