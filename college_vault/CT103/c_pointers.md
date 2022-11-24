# pointers
##### definition
a variable whose value is the address of another variable

%p is the placeholder for the stored address
_// note: prints leading zeroes, unlike %x_

### \* operator
used to define a pointer
e.g.
```c
char c = 'l';
char* c_point = &c;
// defines a character pointer, and passes it the address of c
```

### dereferencing
using a pointer to get to the variable
e.g.
```c
printf("here is a character: %c", *c_point); // <- dereferencing
printf("and here is its address: %p", c_point); // not dereferencing
// or
*c_point = 'a'; // assigning a new character to c
```

---
## pointers and arrays
e.g.
```c
int arr_a[5] = {1, 2, 3, 4, 5};
int* ap_0 = arr_a; // now points to the 0th element of the array

```
// note: this only points to a single element, not the full array
// if we needed to pass the array to a function, for example, passing \*ap wouldn't compile
```c
int (*ap_1)[5] = &arr_a; // this points to the full array
// basically an array of pointers
```

---
## pointers and strings
```c
char string[] = "test sentence";

char* cp;
cp = string; 
puts(cp); 
// a string name often evaluates to a pointer to the string
// this is referred to as the array "decaying" to a pointer

cp = &string;
puts(cp);
cp = &string[0];
puts(cp);
// both of these work, as puts() starts printing from the address passed to it
```

---
## pointers and functions
if a function expects a pointer as an argument, an array of the same type can also be passed to it, as arrays decay to pointers

e.g.
```c
void do_thing(int* p){
	// do thing
}

void main() {
	int arr[2] = {1, 5};
	do_thing(arr);    // works fine
}
```

---
### incrementing pointers
when we increment a pointer (e.g. with ++), we're not adding one, we're adding the size of the data type in bytes to the pointer

-> this is what causes errors when you increment a pointer out of bounds

e.g.
```c
num[2] = {1, 5};
int* ip = num;
for (int i = 0; i < 2; i++) {
	printf("%d ", *(ip+1));
}
// prints "1, 5"
```

---
##### memory requirements
- char: 1 bit
- int: 4 bits
- double: 8 bits

note: see [[misc_programming#memory requirements|here]]

when incrementing a pointer, such as with \*(pointer + i) in a for loop, the pointer is actually incremented by i\*sizeof(\<datatype>)

> #c #programming 