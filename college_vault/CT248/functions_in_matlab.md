# functions in matlab
functions are in their own source files
differs from script files in that they can only communicate with specified inputs and outputs
functions can also be passed as parameters to other functions - callbacks
general syntax
```matlab
% file: name.m

function[outarg1, outarg2, ..., outarg_n] = name(inargs)
% comments here are displayed with "help <fname>"
	%{
		do things
	%}
end
```

### local variables
anything defined inside a function is not accessible outside it, and only exists in the function's workspace (separate from the base one)
### global variables
define it in the base script and the function with global
e.g.
```matlab
global X
```
### persistent variables
remain persistent between function calls
initially an empty array
e.g.
```matlab
% function persist
% persistent counter

if isempty(counter)
	counter = 1;
else
	counter = counter + 1;
end
```

## vector arguments
in and out args can be vectors

## closures
can return contained functions to outer calls
same as in js

a function can be called with all, some, or none of its arguments, same as output
nargin displays the args passed

## subfunctions
the m-file may contain multiple functions, but the first (the one that has the name of the file) is the primary function, and all others are the subfunctions

> #matlab #modelling 