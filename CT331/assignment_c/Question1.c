#include <stdio.h>

int main(int arg, char* argc[]){
  // question 1
  int num = 7;
  int* num_ptr = &num;
  long long_num = 77;
  double dbl = 5.5;
  double* dbl_ptr = &dbl;
  char c = 'a';
  char* c_ptr = &c;
  char** c_ptr_ptr = &c_ptr;

  printf("%-28s\tsize: %d\n", "type: int", sizeof(num));
  printf("%-28s\tsize: %d\n", "type: int pointer", sizeof(num_ptr));
  printf("%-28s\tsize: %d\n", "type: long", sizeof(long_num));
  printf("%-28s\tsize: %d\n", "type: double pointer", sizeof(dbl_ptr));
  printf("%-28s\tsize: %d\n", "type: char pointer pointer", sizeof(c_ptr_ptr));
}