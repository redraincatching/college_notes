###### formatting int display
can print out using %xd, where x is any integer
the x specifies how many characters to print out with the array

-> if you're printing out the number 10 with %3d, printf will print " 10", adding a space beforehand
_// works for float and characters too_
   
###### breakpoints
handy way to see what your code is doing
stops the program at the given point

you can inspect the values of variables, etc. at a given point with breakpoints

###### atof()
converts a string to a float
usage
```c
atof(&<string>);
```

###### atoi()
same as atof, but to int
```c
atoi(&str);
```

###### memory requirements
different variables have different space requirements
sizeof() returns the size (in bytes) of any variable you pass to it, including structs and bytes

we store variables in ram, and we can use &\<variable> to access its address

> #programming 