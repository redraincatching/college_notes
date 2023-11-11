#include <stdio.h>
#include "tests.h"
#include "linkedList.h"

void runTests(){
  printf("Tests running...\n");
  listElement* l = createEl("Test String (1).", 30);
  //printf("%s\n%p\n", l->data, l->next);
  //Test create and traverse
  traverse(l);
  printf("\n");

  //Test insert after
  listElement* l2 = insertAfter(l, "another string (2)", 30);
  insertAfter(l2, "a final string (3)", 30);
  traverse(l);
  printf("\n");

  // Test delete after
  deleteAfter(l);
  traverse(l);
  printf("\n");

  // my additions
  printf("--- question 2 ---\n\n");

  // test length
  printf("list length: %d\n\n", length(l));

  // test push to head
  push(&l, "the new head of the list", 30);
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