/*
assignment 12
2022/01/24
éidhne kennedy
*/

#include <stdio.h>

typedef struct {
	char date[8];
	char region[10];
	char rep[15];
	char item[15];
	int units;
	float unit_cost;
	float total;
}ROW;	// for storing a row of the file

void print_row(ROW curr_row);				// print out each line of the file

void main() {
	FILE* fptr;				// initialising the file pointer
	int no_order = 0;		// total number of orders
	float income = 0;		// total income
	char line[201];			// initialise the array for fgets
	ROW curr_row = {" ", " ", " ", " ", 0, 0.0, 0.0};			// struct for printing the rows

	fopen_s(&fptr, "sample_data.txt", "r");		// open file with relative address
												// it's in the same folder


	if (fptr == NULL) {			// error handling
		printf("error opening file, exiting...\n");
		return;
	}

	fgets(line, 201, fptr);				// gets the first line from the string
	char* token = strtok(line, "\t");	// tab delimited, so breaks up the string
	while (token != NULL) {
		printf("%15s", token);			// prints out the headers for each column
		token = strtok(NULL, "\t");		// step to next token
	}
	while (!feof(fptr)) {
		fscanf_s(fptr, "%s\t", curr_row.date, 8);
		fscanf_s(fptr, "%s\t", curr_row.region, 10);
		fscanf_s(fptr, "%s\t", curr_row.rep, 15);
		fscanf_s(fptr, "%s\t", curr_row.item, 15);
		fscanf_s(fptr, "%d\t", &curr_row.units);
		fscanf_s(fptr, "%f\t", &curr_row.unit_cost);
		fscanf_s(fptr, "%f\t", &curr_row.total);
		print_row(curr_row);
		income += curr_row.total;		// add to total income
		no_order++;						// increment the number of orders
	}
	printf("\nthe total income from all orders was %.2f", income);
	printf("\nthe average income from all orders was %.2f\n", income / no_order);
	fclose(fptr);		// close file

	ROW new_row = { "25/01/22", "Galway", "Kennedy", "Pen", 21, 19.99, 419.79 };	// using previous struct for new row

	fopen_s(&fptr, "sample_data.txt", "a");		// opening again in append mode
	if (fptr == NULL) {			// error handling
		printf("error opening file, exiting...\n");
		return;
	}
	fprintf(fptr, "%s\t%s\t%s\t%s\t%d\t%f\t%f\n", new_row.date, new_row.region, new_row.rep, new_row.item, new_row.units, new_row.unit_cost, new_row.total);
	fclose(fptr);
}


void print_row(ROW curr_row) {
	printf("%15s %15s %15s %15s %15d %15.2f %15.2f\n", curr_row.date, curr_row.region, curr_row.rep, curr_row.item, curr_row.units, curr_row.unit_cost, curr_row.total);
}
