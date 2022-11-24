# Conditional Operator
Returns a value after checking if an expression is true or false.

**syntax**
```c
(<expression>) ? <value if true> : <value if false>;
```
this value can be anything -
a character, a number, a function call, anything.
&nbsp&nbsp&nbsp&nbspfor a function, enclose in brackets

/\*
this can be really useful
```c
printf("you have %d apple%c", n, (n>1) ? "s" : " ";
```
the conditional operator is evaluated before the print statement executes
\*/

> #c #programming
> [[c_standard_input-output_library]] [[c_functions]]