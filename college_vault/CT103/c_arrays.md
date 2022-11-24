# Arrays

a data structure consisting of a collection of elements, each identifiable by an index
used to store a collection of data, like a lot of variables of the same type

### Defining an Array

```c
<type> <name>[<length>];
       // e.g.
            int vals[3];
            char initials[12];

   // you can also initialise at the same time
     //   e.g.
            int vals[3] = {14, 5, 7};    // 14, 5, and 7 are the elements
                                         // 0, 1, and 2 are their index

       // initialising
            int ages[5] = {1, 2, 3, 4, 5}; // correct
            int ages[]; // incorrect
            int ages[] = {1, 2, 3, 4, 5} // correct

    // arrays start at zero.
```

### Storing an Element in an Array

```c
<array_name>[<index>] = <value_to_store>;
   // e.g.
        characters[5] = H;
```

### Using Data in Arrays

```c
<array_name>[<index>];
    // e.g.
        printf("at index 2 in this array is %d", array[1]);
        // note, the placeholder character used is related to the type of array
```
---
## Arrays and [[c_loops|Loops]]

when accessing arrays, variables are valid arguments (well, integers)

```c
// e.g.
for (int i = 0; i < 5; i++) {
            printf("%f ", grades[i]);
        }
```
---
### Arrays in Memory

an array is normally stored in sequential blocks of memory (ram) block size depends on the number of bytes required to store that type of variable

each block of memory has an address (hex), and functions like scanf need those addresses
&nbsp&nbsp&nbsp&nbsp→ that's why we pass it their addresses with &

---
## 2d Arrays

syntax
```c
<type> <name>[<row length>][<column length>]
```

e.g.

```c
int var[2][2] = {{11, 12} {21, 22}};
```

changing elements is similar

```c
int var[0][5] = 14;
```

### Looping over a 2d Array
you need 2 loops; an outer loop for the rows, an inner loop for the columns

e.g.

```c
int x[5][5];
int r, c, val = 0;

// set array values
for (r = 0; r < 4; r++) {
    for (c = 0; c < 4; c++) {
        x[r][c] = val;
        val++;
    }
}

// output values
for (r = 0; r < 4; r++) {
    for (c = 0; c < 4; c++) {
        printf("%d\\t", x[r][c]);    // using \\t to space out entries with tabs
    }
    printf("\\n");
}
```

### 2d Array from User Input

```c
int x[3][3];
int r, c;

for (r = 0; r < 3; r++) {
    for (c = 0; c < 3; c++) {
        printf("enter x[%d][%d]: ", r, c);
        scanf_s("%d", &x[r][c]);
    }
}
```

---
### Passing Arrays to Functions
in order to accept arrays as function parameters, we have to specify its parameters as follows

```c 
<type> <function> (<type> <array>[]) {}
// note the [], indicating that it is an array being passed
```

#### passing a string as a parameter
just a character array, so can be passed as above, or as a pointer, as seen [[c_strings#Strings and Functions|here]]

// passing strings as [[c_pointers|pointers]] is the accepted convention in c
//you can pass int arrays as pointers, too

> #c #programming 
> [[c_standard_input-output_library]]