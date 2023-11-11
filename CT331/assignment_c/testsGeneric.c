#include <stdio.h>
#include "testsGeneric.h"
#include "genericLinkedList.h"

void runTests(){
  printf("Tests running...\n");
  listElement* l = createEl("this one is a string", 30, STRING);
  // printf("%s\n%p\n", l->data, l->next);
  //Test create and traverse
  traverse(l);
  printf("\n");

  int data_int = 123456;
  double data_double = 101.101;

  //Test insert after
  listElement* l2 = insertAfter(l, &data_int, 30, INT);
  insertAfter(l2, &data_double, 30, DOUBLE);
  traverse(l);
  printf("\n");

  // Test delete after
  deleteAfter(l);
  traverse(l);
  printf("\n");

  // my additions
  printf("--- question 3 ---\n\n");

  // test length
  printf("list length: %d\n\n", length(l));

  // test push to head
  push(&l, "the new head of the list", 30, STRING);
  traverse(l);
  printf("\n");

  // test pop
  pop(&l);
  traverse(l);
  printf("\n");

  printf("enqueue just calls push, i'm not testing that twice\n\n");

  // test dequeue
  dequeue(l);
  traverse(l);

  printf("\nTests complete.\n");
}