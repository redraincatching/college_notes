#ifndef CT331_ASSIGNMENT_LINKED_LIST
#define CT331_ASSIGNMENT_LINKED_LIST

typedef struct listElementStruct listElement;

typedef enum {STRING, INT, DOUBLE} Type;  // for ease of selecting print function

//Creates a new linked list element with given content of size
//Returns a pointer to the element
listElement* createEl(void* data, size_t size, Type type);

//Prints out each element in the list
void traverse(listElement* start);

//Inserts a new element after the given el
//Returns the pointer to the new element
listElement* insertAfter(listElement* after, void* data, size_t size, Type type);

//Delete the element after the given el
void deleteAfter(listElement* after);

//get the length of a given list
int length(listElement* head);

// push a new element onto the head of a list
void push(listElement** list, void* data, size_t size, Type type);

// pop an element from the head
listElement* pop(listElement** list);

// enqueue an element at the head of a list
void enqueue(listElement** list, void* data, size_t size, Type type);

// dequeue an element from the tail of a list
listElement* dequeue(listElement* list);

// printer functions
void printString(void *data);
void printInt(void *data);
void printDouble(void *data);

#endif