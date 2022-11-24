#include <stdio.h>

void change_dogs(FILE* fptr);		// change the dogs.txt file
void countryfile(FILE* fptr);		// i know it's not proper naming convention, but i had to

void main() {
	FILE* fptr_0;
	FILE* fptr_1;
	fopen_s(&fptr_0, "C:\\Users\\eidhn\\Downloads\\dogs.txt", "r+");		// open dogs.txt
	fopen_s(&fptr_1, "C:\\Users\\eidhn\\Downloads\\countries.txt", "r+");	// open countries.txt

	change_dogs(fptr_0);
	countryfile(fptr_1);
}

void change_dogs(FILE* fptr) {
	if (fptr != NULL) {
		fseek(fptr, 0, SEEK_END);			// seek to end of file
		int len = ftell(fptr);				// get current position in file (i.e. the end) and return how far into the file stream it is
		printf("the file is of length %ld\n", len);

		fseek(fptr, -3, SEEK_END);			// go to end of file, step back 3 chars ("Pug") and overwrite with "Boxer"
		fprintf(fptr, "Boxer");
	}
}

void countryfile(FILE* fptr) {
	char line[201];
	char country[35];
	int population;

	if (fptr != NULL) {
		int i = 0, j = 0;
		while (!feof(fptr)) {
			fgets(line, 201, fptr);
			while (line[i] != '\t') {	// tab delimited
				country[j] = line[i];	// step through the line, until the tab, adding the string to the country array char by char
				i++;
				j++;
			}
			country[j] = '\0';		// make it a string
			i++;

			population = atoi(&line[i]);	// atoi the rest of the line
			printf("country: %25s,\tpopulation: %15d\n", country, population);	// print out
			i = 0, j = 0;					// reset
		}

		fseek(fptr, 0, SEEK_END);
		fprintf(fptr, "\nEstonia\t1326535");
	}
}
