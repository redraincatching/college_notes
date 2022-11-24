#include <stdio.h>
void main() {

    int visitors[7];
    int sum_visit = 0;
    int avg_visit = 0;

    for (int i = 0; i < 7, i++) {
        printf("ener the visitors for day %d: ", i+1);
        scanf_s("%d", &visitors[i]);
        sum_visit += visitors[i];
    }

    avg_visit = sum_visit / 7;
    printf("average daily visitors: %d\n", sum_visit);

    for (int i = 0; i < 7; i++) {    // find out which days were below average
        if (visitors[i] < avg_visit) {
            printf("day %d visitors were %d, less than the average\n", i+1, visitors[i]);
        }
    }

}
