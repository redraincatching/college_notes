#include <stdio.h>

typedef struct {
	int n, s, e, w, in, out;	// responses to directional commands
	char desc[101];				// description
}LOCATION;

int read_loc(char* filepath);	// reads in the locations
LOCATION* direction(char* input, LOCATION* loc);	// move in a direction
void look(LOCATION* loc);				// look at the current location
void help();					// display instructions


LOCATION locations[25];

void main() {
	char* filepath = "locations.txt";
	char input[20];						// input string
	int no_locs = read_loc(filepath);		// read in from file, return how many locations are in the game
	LOCATION* curr_loc = &locations[1];		// pointer to address of location 1

	puts("welcome to the game");
	printf("%s\n", curr_loc->desc);
	do {
		printf("> ");
		scanf_s("%s", &input, 20);

		if (strcmp(tolower(input), "n") == 0 || strcmp(tolower(input), "s") == 0 || strcmp(tolower(input), "e") == 0 || strcmp(tolower(input), "w") == 0 || strcmp(tolower(input), "in") == 0 || strcmp(tolower(input), "out") == 0) {
			curr_loc = direction(input, curr_loc);
            // basically, if(direction)
			printf("%s\n", curr_loc->desc);
		}
		else if (strcmp(tolower(input), "look") == 0) {
			look(curr_loc);
		}
		else if (strcmp(tolower(input), "help") == 0) {
			help();
		}
		else if (strcmp(tolower(input), "quit") == 0) {
			puts("thanks for playing :)");
			break;
		}
		else {
			puts("please enter a valid command");
		}
	} while (1 == 1);

}

int read_loc(char* filepath) {
	FILE* fptr;
	char line[101];		// buffer for readin
	int count = 0;		// skip top two lines of headers
	int id = 1, temp = 0;

	fopen_s(&fptr, filepath, "r");

	while (fgets(line, 101, fptr) != NULL) {
		if (count < 2) {
			count++;
		}
		else {		// note here: sscanf_s requires an argument specifying the size of desc
			sscanf_s(line, "%d\t%d\t%d\t%d\t%d\t%d\t%d\t%[^\n]", &temp, &locations[id].n, &locations[id].s, &locations[id].e, &locations[id].w, &locations[id].in, &locations[id].out, locations[id].desc, 101);
			id++;
			count++;
		}
	}

	fclose(fptr);
	return count - 1;
}

LOCATION* direction(char* input, LOCATION* loc) {
	if (strcmp(tolower(input), "n") == 0) {		// if the direction input was north
		if (loc->n != 0) {					// and north is a valid direction
			return &locations[loc->n];		// go north
		}
		else {
			printf("you can't go north from there.\n");		// otherwise, stay there
			return loc;		// this is the same for every direction
		}
	}
	if (strcmp(tolower(input), "s") == 0) {
		if (loc->s != 0) {
			return &locations[loc->s];
		}
		else {
			printf("you can't go south from there.\n");
			return loc;
		}
	}
	if (strcmp(tolower(input), "e") == 0) {
		if (loc->e != 0) {
			return &locations[loc->e];
		}
		else {
			printf("you can't go east from there.\n");
			return loc;
		}
	}
	if (strcmp(tolower(input), "w") == 0) {
		if (loc->w != 0) {
			return &locations[loc->w];
		}
		else {
			printf("you can't go west from there.\n");
			return loc;
		}
	}
	if (strcmp(tolower(input), "in") == 0) {
		if (loc->in != 0) {
			return &locations[loc->in];
		}
		else {
			printf("you can't go in from there.\n");
			return loc;
		}
	}
	if (strcmp(tolower(input), "out") == 0) {
		if (loc->out != 0) {
			return &locations[loc->out];
		}
		else {
			printf("you can't go out from there.\n");
			return loc;
		}
	}
}

void look(LOCATION* loc) {
	// prints the description of the current location
	printf("%s\n", loc->desc);
}

void help() {	// prints the valid commands
	printf("i know these commands:\nn, s, e, w, in, out, look, help, quit\n");
}
