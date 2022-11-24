# memory allocation
## static vs dynamic memory allocation
#### static arrays
- size defined at compile time
- memory stored on the stack
- stack grows when entering new blocks (branches, loops, functions)
- stack shrinks when leaving blocks
#### dynamic array
- memory stored on the heap
- stays available until removed
- in c, removed manually with function calls
- in newer languages, e.g. java, this is done automatically by garbage collection
	// no risk of memory leak

### why have dynamic memory?
- input of unknown size
- some data structures require it
- basically, flexibility and efficiency

---
## sizeof
the sizeof operator returns the number of bytes reserved for a variable or data type
determines:
- byte length of a simple data type
- number of bytes required for a user-defined data type
- byte length of an array

// note: modern processors often move multiple bytes at a time, so something like a struct might be larger than expected

---
## dynamic memory functions in <stdlib.h>
- malloc()
allocate a memory block
- free()
deallocate a previously allocated block
// note: don't need to specify the size of the memory, windows registers every allocated block, so it knows
- calloc()
allocate space for an array
- realloc()
change size of previously allocated memory

### malloc
allocates a block of memory of _size_ bytes, or a NULL pointer if it fails
prototype
```c
void* malloc(size);
```
sample usage
```c
int* array_of_ints = (int*) malloc(sizeof(int) * whatever_variable);
```

> #c #programming 