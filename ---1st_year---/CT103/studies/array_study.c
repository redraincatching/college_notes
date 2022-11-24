#include <stdio.h>
void main() {
    int num;

    printf("enter the number of 5k times to store: ");
    scanf_s("%d", &num);
    printf("\n");

    float run_times[num];

    for (int i = 0; i < num; i++) {
        printf("enter the time for run %d: ", i+1);
        scanf_s("%f", &run_times[i]);
    }

    for (int i = 0; i < num; i++) {
        printf("your time for run %d is %.2f", i + 1, run_times[i]);
    }

}
