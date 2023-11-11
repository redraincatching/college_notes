#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "genericLinkedList.h"

typedef struct listElementStruct
{
  void *data;
  size_t size;
  struct listElementStruct *next;
  void (*printer)(void *);
} listElement;

// Creates a new linked list element with given content of size
// Returns a pointer to the element
listElement *createEl(void *data, size_t size, Type type)
{
  // switch the size we're allocating for depending on the primitive type stored
  int type_size;
  switch (type)
  {
  case STRING:
    type_size = 1;
    break;
  case INT:
    type_size = 4;
    break;
  case DOUBLE:
    type_size = 8;
    break;
  }
  listElement *e = (listElement *)malloc(sizeof(listElement));
  if (e == NULL)
  {
    // malloc has had an error
    printf("malloc error on creation");
    return NULL; // return NULL to indicate an error.
  }
  char *dataPointer = malloc(sizeof(type_size) * size);
  if (dataPointer == NULL)
  {
    // malloc has had an error
    free(e);     // release the previously allocated memory
    return NULL; // return NULL to indicate an error.
  }
  memcpy(dataPointer, data, size); // more versatile than strcpy
  e->data = dataPointer;
  e->size = size;
  e->next = NULL;
  // choose the print function
  switch (type)
  {
  case STRING:
    e->printer = &printString;
    break;
  case INT:
    e->printer = &printInt;
    break;
  case DOUBLE:
    e->printer = &printDouble;
    break;
  };
  return e;
}

// Prints out each element in the list
void traverse(listElement *start)
{
  listElement *current = start;
  while (current != NULL)
  {
    current->printer(current->data);  // calling the function rather than printf
    current = current->next;
  }
}

// Inserts a new element after the given el
// Returns the pointer to the new element
listElement *insertAfter(listElement *el, void *data, size_t size, Type type)
{
  listElement *newEl = createEl(data, size, type);
  listElement *next = el->next;
  newEl->next = next;
  el->next = newEl;
  return newEl;
}

// Delete the element after the given el
void deleteAfter(listElement *after)
{
  listElement *delete = after->next;
  listElement *newNext = delete->next;
  after->next = newNext;
  // need to free the memory because we used malloc
  free(delete->data);
  free(delete);
}

// my additions

int length(listElement *head)
{
  // variation on traverse, although would be more fun to do recursively
  listElement *current = head;
  int count = 0;
  while (current != NULL)
  {
    ++count;
    current = current->next;
  }
  return count;
}

void push(listElement **list, void *data, size_t size, Type type)
{
  // first, create the new element
  listElement *new_el = createEl(data, size, type);
  // then, if that worked, we assign the old head as the "next" element after the new one
  if (new_el != NULL)
  {
    new_el->next = *list;
  }
  // then change the original list via side effects
  *list = new_el;
}

listElement *pop(listElement **list)
{
  // save the element to be popped
  listElement *out = *list;
  // change the referenced list's head
  *list = (*list)->next;
  // return
  return out;
}

void enqueue(listElement **list, void *data, size_t size, Type type)
{
  // just for clarity when working with a list i guess
  push(list, data, size, type);
}

listElement *dequeue(listElement *list)
{
  listElement *current = list;
  listElement *prev;
  while (current->next != NULL)
  {
    // using a check on next in case it's a single element list
    prev = current;
    current = current->next;
  }

  // make sure we don't have a memory leak
  if (current->data != NULL)
  {
    free(prev->next->data);
  }

  // so now we have the last two elements of the list, return the last and set prev's next to NULL
  prev->next = NULL;
  return current;
}

// printfunctions
// these just cast to whatever type then printf
void printString(void *data)
{
  printf("%s\n", (char *)data);
}

void printInt(void *data)
{
  printf("%d\n", *(int *)data);
}

void printDouble(void *data)
{
  printf("%lf\n", *(double *)data);
}