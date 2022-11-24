/*
assignment 11
2022/01/18
éidhne kennedy
*/

#include <stdio.h>
#include <time.h>
#include <math.h>

//#define grid_size 10
#define grid_size 9						// using 9, not my actual number, 1

void init_xy();							// initialise x and y
void visualise_grid();					// print the grid to terminal
void random_search(int size);			// random search, pretty self-explanatory
void grid_search(int size, int locs);	// sequential, iterative search
int ship_x, ship_y;						// global variables for ship


void main() {
	init_xy();
	visualise_grid();

	random_search(grid_size);
	grid_search(grid_size, 0);
}

void init_xy() {
	srand(time(NULL));
	ship_x = rand() % grid_size;
	ship_y = rand() % grid_size;
}

void visualise_grid() {		// this is all just to make it look pretty
	for (int i = -1; i <= grid_size; i++) {
		printf("---");
	}
	printf("\n");

	for (int i = 0; i < grid_size; i++) {
		for (int j = -1; j <= grid_size; j++) {
			if (i == ship_y && j == ship_x) {
				printf(" # ");
			}
			else if (j == -1 || j == grid_size) {
				printf(" | ");
			}
			else {
				printf("   ");
			}
		}
		printf("\n");
	}

	for (int i = -1; i <= grid_size; i++) {
		printf("---");
	}
	printf("\n");
}

void random_search(int size) {
	srand(time(NULL) * 8);		// randomise again, cause why not

	int found = 0;				// if boat has been found
	int r_x, r_y;				// randomised x and y
	int loc_check = 0;			// no. of locations checked

	while (!found) {
		r_x = rand() % size;
		r_y = rand() % size;

		if (r_x == ship_x && r_y == ship_y) {
			found = 1;
		}

		loc_check++;			// no. of iterations
	}

	puts("\n --- random search --- ");
	printf("ship found at location %d, %d after %d attempts\n", r_x, r_y, loc_check);
}

void grid_search(int size, int locs) {
	int x = locs % size;		// go through each row, 1 move per repeat
	int y = floor(locs / 10);	// go through each column, 1 move per 10 repeats

	if (x == ship_x && y == ship_y) {
		puts("\n --- grid search --- ");
		printf("ship found at location %d, %d after %d attempts\n", x, y, locs);
	}
	else {
		grid_search(size, locs + 1);		// recursion
	}
}
