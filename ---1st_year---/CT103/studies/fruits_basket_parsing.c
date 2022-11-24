#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main() {
    FILE* fptr;
    char line[201];
    char fruit[20], variety[20];
    double price;
    fopen_s(&fptr, "fruit.txt", "r");

    if (fptr != NULL) {
        int i = 0, j = 0;
        while(!feof(fptr)) {
            fgets(line, 201, fptr);
            while (line[i] != '\t') {   // tab delimited, step through char by char
                fruit[j] = line[i];     // pass the value into the "fruit" array
                i++;
                j++;
            }
            fruit[j] = '\0';            // make it a string, not a char array
            i++;
            j = 0;                      // so we can use the same variable for the next field

            while (line[i] != '\t') {   // similar process, for next field
                variety[j] = line[i];
                i++;
                j++;
            }
            variety[j] = '\0';
            i++;
            price = atof(&line[i]);     // change string to float
            printf("fruit: %20s, variety: %20s,\t\tprice: %.2f", fruit, variety, price);
            i = 0, j = 0;
        }
    }

    fclose(fptr);
}
