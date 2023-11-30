#include <stdio.h>

int main() {
	int num, original, rem, sum = 0;

	printf("enter a three-digit number: ");
	scanf("%d", &num);
	original = num;

	while (original != 0) {
		rem  = original % 10;
		sum = sum + rem * rem * rem;
		original = original /10;
	}

	if (sum == num) {
		printf("%d is an armstrong number", num);
	} else {
		printf("%d is not an armstrong number", num);
	}

	return 0;
}
