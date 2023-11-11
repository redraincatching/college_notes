#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"

typedef struct listElementStruct{
  char* data;
  size_t size;
  struct listElementStruct* next;
} listElement;

//Creates a new linked list element with given content of size
//Returns a pointer to the element
listElement* createEl(char* data, size_t size){
  listElement* e = malloc(sizeof(listElement));
  if(e == NULL){
    //malloc has had an error
    return NULL; //return NULL to indicate an error.
  }
  char* dataPointer = malloc(sizeof(char)*size);
  if(dataPointer == NULL){
    //malloc has had an error
    free(e); //release the previously allocated memory
    return NULL; //return NULL to indicate an error.
  }
  strcpy(dataPointer, data);
  e->data = dataPointer;
  e->size = size;
  e->next = NULL;
  return e;
}

//Prints out each element in the list
void traverse(listElement* start){
  listElement* current = start;
  while(current != NULL){
    printf("%s\n", current->data);
    current = current->next;
  }
}

//Inserts a new element after the given el
//Returns the pointer to the new element
listElement* insertAfter(listElement* el, char* data, size_t size){
  listElement* newEl = createEl(data, size);
  listElement* next = el->next;
  newEl->next = next;
  el->next = newEl;
  return newEl;
}


//Delete the element after the given el
void deleteAfter(listElement* after){
  listElement* delete = after->next;
  listElement* newNext = delete->next;
  after->next = newNext;
  //need to free the memory because we used malloc
  free(delete->data);
  free(delete);
}


// my additions

int length(listElement* head) {
  // variation on traverse, although would be more fun to do recursively
  listElement* current = head;
  int count = 0;
  while(current != NULL) {
    ++count;
    current = current->next;
  }
  return count;
}

void push(listElement** list, char* data, size_t size) {
  // first, create the new element
  listElement* new_el = createEl(data, size);
  // then, if that worked, we assign the old head as the "next" element after the new one
  if (new_el != NULL) {
    new_el->next = *list;
  }
  // then change the original list via side effects
  *list = new_el;
}

listElement* pop(listElement** list){
  // save the element to be popped
  listElement* out = *list;
  // change the referenced list's head
  *list = (*list)->next;
  // return
  return out;
}

void enqueue(listElement** list, char* data, size_t size) {
  // just for clarity when working with a list i guess
  push(list, data, size);
}

listElement* dequeue(listElement* list) {
  listElement* current = list;
  listElement* prev;
  while (current->next != NULL) {
    // using a check on next in case it's a single element list
    prev = current;
    current = current->next;
  }

  // make sure we don't have a memory leak
  if (current->data != NULL) {
    free(prev->next->data);
  }

  // so now we have the last two elements of the list, return the last and set prev's next to NULL
  prev->next = NULL;
  return current;
}

