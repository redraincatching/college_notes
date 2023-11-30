# C
- procedural, imperative, structural, "systems language"
- came into being in 1969-1973 in parallel with the development of the unix os

```c
int main(int argc, char* argc[]) {
	// code...
	// can use main's return for error codes, or to write a higher-level code into a .bat file
	// not to be confused with the batfiles, which batman keeps on the justice league
}
```

 - bcpl -> b -> c -> ...
- ansi standard since the 1980s
- now one of the most popular and powerful languages today
	- probably still the fastest portable/general language today

- compiler now only makes minimal necessary changes, so if you add a semicolon or a single function, it just compiles the minimal necessary to recompile fully

when unix was being created, the DEC PDP-7 was too cramped to even compile it, so it was written on a completely different machine - the GEMAP assembler on a GE-3635 - to create physical ticker tape to allow the unix os to be created, with a primitive kernel, editor, assembler, shell, and commands like rm, ls, cat, echo...

bcpl, b, and c all fit in the traditional procedural family typified by fortran and algol 60
incredibly small code, very close to the machine
rely on library routines for io and other os interactions, which make them so portable (different libraries are all that are necessary to change machines)

## examining hello world
```c
#include <stdio.h>      
// header inclusion, provides instructions to the c linker as to which libraries to include

void say_hello();
// function prototype, tells the compiler the function exists before its implementation
// allows the compiler to handle functions calling each other, and recursion

int main(int argc, char* argv[]) {
	say_hello();        // calling a function
	return 0;
}

void say_hello() {
	// function definition
	printf("hello world!");     // printf takes char*
}
```

### another sample program - adder
```c
#include <stdio.h>

int add(int a, int b);

int add(int a, int b) {
	return a+b;
}

int main(int argc, char* argv[]) {
	int first = 8;
	int second = 4;
	printf("the first number is: %d\nthe second is: %d\n", first, second);

	// note: %d is specifically a flag for decimal ints, %i handles ints in all bases

	printf("result: %d\n", add(first, second));
}
```

---
## pointers
see also: [[c_pointers]]

let
```c
int i = 8;
int* p = &i;
```

turn a pointer into a value with \* - dereferencing
```c
int i2 = *p;
```
get the reference to a value with &
```c
int* p2 = &i;
```

### "breaking" rules with pointers
```c
int a = 8;
int b = 9;
swap(&a, &b);   // swaps the addresses

void swap(int* x, int* y) {
	int temp = *x;  // hold value of x
	*x = *y;        // change the value of x
	*y = temp;      // change y
}

// args by convention shouldn't be affected by a function, however this can be done by passing in addresses and messing with them
// the arguments themselves - the addresses - don't change, but the variables do via the side effect
```

### arrays and pointers
```c
// arrays decay to pointers in c

int int_arr[5];
// int_arr is a pointer to the first element of the array, decays to &int_arr[0]

int_arr[2] = 3;
// is the same as
*(int_arr + 2) = 3;

// the + operator here is not simple addition, it's moving the pointer that many times by the size of its type
// so the pointer gets moved over 4 bytes, or to the second location
// that is, historically, why arrays start at 0, the first location is 0 steps over, so it saves a subtraction that would have to be carried out evrey time the array is accessed otherwise
```

### swap function in c
it's trivial to write a function in c that swaps the values of two variables, but only if we define the type that it operates on, like so
```c
void swap(int* x, int* y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}
```
what about one that works on any data type?
```c
void swap(void* x, void* y) {
	void temp = *x;     
	// doesn't work, we can't give temp a size as void has none
	*x = *y;
	*y = temp;
}

// we can, however, have a void* type
```

### void\*
- specific pointer type, but not specifying what type it's pointing to
- points to _some_ location in memory
- no specific size, but pointers don't really need one

### sizeof(type)
returns the size, in bytes, of the given type
built in to c

### memcpy()
```c
void* memcpy(void* to, const void* from, size_t size)
```
copies size bytes from the memory beginning at ___from___ to memory beginning at ___to___
returns the value of to
// even void functions return but void is no data, void\* is an unspecified pointer
defined in string.h

with all that in mind, here's a working generic swap
```c
void g_swap(void* vp1, void* vp2, int size) {
	// only works for two variables of the same size
	// sorta, otherwise data leaks and shit
	char* temp_buf = (char*) malloc(size);

	memcpy(temp_buf, vp1, size);
	memcpy(vp1, vp2, size);
	memcpy(vp2, temp_buf, size);
}
```


---
###### extra! memcpy source code
```c
void *memcpy(void *dst, const void *src, size_t len) {
	size_t i;

	/*
	 * memcpy does not support overlapping buffers, so always do it
	 * forwards. (Don't change this without adjusting memmove.)
	 *
	 * For speedy copying, optimize the common case where both pointers
	 * and the length are word-aligned, and copy word-at-a-time instead
	 * of byte-at-a-time. Otherwise, copy by bytes.
	 *
	 * The alignment logic below should be portable. We rely on
	 * the compiler to be reasonably intelligent about optimizing
	 * the divides and modulos out. Fortunately, it is.
	 */

	if ((uintptr_t)dst % sizeof(long) == 0 &&
		(uintptr_t)src % sizeof(long) == 0 &&
		len % sizeof(long) == 0) {

			long *d = dst;
			const long *s = src;

			for (i=0; i<len/sizeof(long); i++) {
					d[i] = s[i];
			}
	}
	else {
			char *d = dst;
			const char *s = src;

			for (i=0; i<len; i++) {
				   d[i] = s[i];
			}
	}

   return dst;
}
```

---

## c types
four basic arithmetic type specifiers
- int
- char
- float
- double

four modifiers
- signed
- unsigned
- short
- long

---
> // with sizeof()
> int is only guaranteed to be "equal to or greater than short", which is >= char
> same as long long >= long >= int
> the actual size is platform and compiler dependent
> and when they're combined the space they take up may be messed with for alignment reasons
> 
> there is no fixed size for data types in c
> the size of an int _should_ reflect the native word size of your system
> e.g. in a 32-bit system sizeof(int) returns 4
> 
> on most modern machines
> - short int = 2 bytes
> - int = 4
> - long int = 8 (maybe)
> - long long int = 8 (usually the max)

---
### char
nothing special
just a 1-byte integer

then how does it print a letter?
-> formatted output
what about other integers?
-> yeah, just print using the %c flag

### floats and doubles
represent real values in binary
a finite number of binary representations given a finite number of bits
an infinite number of floats
-> therefore, necessarily imprecise


```text
stored:
	m*b^e
	
	m = mantissa
	b = base
	e = exponent

ieee-754 standard
	bit 31  30     23  22                     0
		s   eeeeeeee    mmmmmmmmmmmmmmmmmmmmmmm

	double uses 64
		11 exp, 52 mantissa
```
see also: [[base_conversion_floating_point]]

### enumerated types
also just an integer
just with a special name

```c
enum flag {constant_1, constant_2, ..., constant_n}
```

enum constants can be given a specified value
// they can actually have the same value
// can mix default and assigned values

```c
enum State = {working = 1, failed = 0, frozen = 0};
enum day = {sunday = 1, monday, tuesday = 5, wednesday, thursday = 10, friday, saturday}
	// not sure why you'd do this one though
```

constants must be unique within their scope
```c
enum state {working, failed};
enum result {failed, passed};
// compiler error
```

### structs
```c
struct structure_name {
	data_type member_0;
	data_type member_1;
	//...
	data_type member_n;
};

struct person {
	// ...
} bob;

struct person {
	// ...
};

struct person bob;


// malloc and structs
/*
if you free memory in a struct, you just free the data stored there
	therefore if a struct has a pointer, that pointer gets freed, but the value stored in it does not
*/

//	e.g.
struct person {
	int age;
	char* first_name;
	char* surname;
} ct331_class[];

// you'd have to use 
if (student->first_name != null) {
	free(first_name);
	// and do the same for the other data
}
free(student);
```

### typedef - user defined types
typedef existing_name alias_name
e.g.
```c
typedef unsigned char BYTE;
BYTE b;
b = 10;

typedef struct {
	char name[30];
	int number;
} STUDENT;
```

typedef doesn't actually create anything new, it just aliases an existing type

---
## dynamic memory allocation
- malloc
- calloc
- free
- realloc

### malloc
```c
void* malloc(size_t size);
```

size is in bytes, sizeof() returns bytes
	-> we can dynamically allocate space with malloc() and sizeof()

sizeof() struct gives the size of the whole struct

### calloc


takes two arguments, the number of elements and their size
slightly more advanced, because it also assigns the value 0 to each of the elements
// malloc just returns the space, calloc also initialises it
// useful for dynamically creating arrays

### free
(bird)
bew new new ew new new new new new new new new new bew new new new newwww new newwww new newwww ne newww newww newww

releases memory, allowing it to be used
takes a single argument - a pointer to the memory being released
no return 
does not delete the values stored in that memory, just changes access

### realloc
changes the size of a referenced block of memory
	// well no, makes a new block and copies the existing data over
takes two arguments
- pointer to the memory currently referenced
- number of bytes now to be pointed to

returns pointer to new block of memory

// super inefficient, don't use it


> #paradigms #c