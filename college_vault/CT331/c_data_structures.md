# data structures in c
## heaps and stacks
### stack
- ordered
- specific limited size
- limited access
- fast
- filo
- push/pop
![[heap-stack_0.png]]

### heap
- unordered
- allocate/free
- unlimited size (in theory)
- global access (threads)
- slower
![[heap-stack_1.png]]

![[heap-stack_2.png]]

---
## linked lists
see also: https://www.data-structures-in-practice.com/intrusive-linked-lists/, and [[intrusive_linked_lists|here]].

### pros:
- dynamic structure
- insertion + deletion easy
- can implement other structures easily
- add/remove from middle of lists

### cons:
- more memory used than array
- sequential access
- nodes not stored contiguously, increases memory read time
- reverse traverse is cumbersome

### operations
- create
- traverse
- insert (after/before\*)
- delete (after/current\*)
- get first element
- get rest of list

\* possible, but have potential issues

#### code
```c
typedef struct listElementStruct {
	char* data;
	size_t size;
	struct listElementStruct* next;
} listElement;

// can also keep a pointer to the head for easy access


listElement* createEl (char* data, size_t size) {
	listElement* e = malloc(sizeof(listElement));
	if (e == NULL) {
		// malloc errored
		return NULL;
	}
	char* dataPointer = malloc(sizeof(char) * size);
	if (dataPointer == NULL) {
		// another malloc error
		free(e);    // release previously allocated memory
		return NULL;
	}
	strcpy(dataPointer, data);
	e->data = dataPointer;
	e->size = size;
	e->next = NULL;
	return e;
}

void traverse(listElement* start) {
	listElement* current = start;
	while(current != NULL) {
		printf("%s\n", current->data);
		current = current->next;
	}
}

listElement* insertAfter(listElement* el, char* data, size_t size) {
	listElement* newEl = createEl(data, size);
	listElement* next = el->next;
	newEl->next = next;
	el->next = newEL;
	return newEl;
}

void deleteAfter(listElement* after) {
	if (after->next == NULL) {
		return;     // last element in list
	}

	listElement* delete = after->next;
	listElemetn* newNext = delete->next;
	after->next = newNext;
	// now free the memory
	free(delete->data);
	free(delete);
}
```


> #paradigms #c 