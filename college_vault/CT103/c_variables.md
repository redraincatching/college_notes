# Variables

Used to temporarily store data to use in programs

## Data Types

-   Integer (int): numbers with no decimal point
-   Floating point (float): numbers with a decimal point
-   Double (double): large floating point number
-   Character (char): single character
-   String (string): multiple characters

Relative sizes
-   bit - 1 or 0
-   byte - 8 bits
-   kilobyte - 1024 bytes (2^10 bytes)
-   megabyte - 1024 kilobytes

---
### Rounding Errors

float - in binary, fractions don't split the same way, so what we see is often rounded
```c
float f = 0.1;
printf("%30.28f", f); // print 30 characters, 28 of which are after the decimal point
					// if we don't specify, C prints 6 places, and rounds to the last

//output = 0.100000001435...
```

#### Naming Conventions
-   unique
-   1-32 characters
-   begin with a letter, followed by letters, numbers, and underscore combination

```c
double annualsalary;    // flat case
double annualSalary;    // camel case
double annual_salary;   // snake case
double Annual_Salary;   // snake-camel case
```

---
### Declaring and Initialising

```c
float salary;          // declared, not initialised
char initial = "d";    // declared and initialised
int age = 0;           // declared and initialised
salary = 35000.00;     // now we initialise salary
```

---
### Storing Data
The assignment operator (=) is used to put data in variables
&nbsp&nbsp&nbsp&nbsp→ take whatever the right hand side evaluates to, and store that

### Printing Out Data
printf takes a number of inputs
&nbsp&nbsp&nbsp&nbsp→ text to print
&nbsp&nbsp&nbsp&nbsp→ placeholders (conversion characters)
&nbsp&nbsp&nbsp&nbsp→ data (separated by commas)

#### Conversion Characters
symbol | function
---|--- 
%d | int
%f|float
%c|char
%s|string
%lf|double
%X|hexadecimal

#### Escape Sequences
symbol | function
---|--- 
\t|tab
\\|real backslash
\'|quote
\n|newline
\a|alarm, beep

---

## Constants

(also called literals)
fixed values that a program cannot change during its execution

**syntax**
```c
const <type> <name> = <value>;
// e.g.
const float gravity = 9.81;     // there's something ironic about "float gravity"
```

you can also declare constants outside of main(), using \#define

this creates what is called a _macro_ (a fragment of code that we've given a name to)

→ whenever this name is called, it is replaced by the contents of the macro
→ there are two kinds of macros, object-like and function-like

**\#define syntax**
```c
#define <name> <value>;
```

###### Function-like Macros
declared similarly to object-like macros

**syntax**
```c
#define <name> (<arguments>) (<function_itself>)
```
---
## Variable Scope
the region of a program where a variable is visible
can be either *local* or *global*

### Local Variables
_declared_ inside a function or code block (like i in a for loop)
-> two local variables with the same name, but declared in two different places, will have different addresses in memory

### Global Variables
declared outside of a function
can be accessed by any function
&nbsp&nbsp&nbsp&nbsp*// remember, main() is still a function*
&nbsp&nbsp&nbsp&nbsp_// macros have global scope_

> #c #programming 
> [[c_introduction]]