/*
eidhne kennedy
21347021
2021/11/30
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int setpasscode(int n);
void rand_search(int code, int n);
void ord_search(int code, int n);

void main() {
	srand(time(NULL));
	int max_no;

	do {
		puts("enter a maximum password size, or a negative number to end program: ");
		scanf_s("%d", &max_no);
	    if (max_no <= 0) { break; }
		int passcode = setpasscode(max_no);
		rand_search(passcode, max_no);
		ord_search(passcode, max_no);
	} while (1);
}

int setpasscode(int n) {			// passcode being set
	int passcode = rand() % (n + 1);
	return passcode;
}

void rand_search(int code, int n) {
	srand(time(NULL)*8);			// so it's not just the same
	int check = 0, counter = 0;
	do {
		check = rand() % (n + 1);
		counter++;
	} while (check != code);
	printf("passcode: %d\nnumber of attempts: %d\n", check, counter + 1);
}

void ord_search(int code, int n) {
	for (int i = 0; i < n; i++) {
		if (i == code) {
			printf("passcode: %d\nnumber of attempts: %d\n", i, i + 1);
			break;
		}
	}
}
