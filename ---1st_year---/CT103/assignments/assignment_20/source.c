#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LOCS 25
#define MAX_ITEMS 5

typedef struct {
	char name[50];		// name of the item
	char desc[101];		// item description
}ITEM;

typedef struct {
	int n, s, e, w, in, out;	// responses to directional commands
	char desc[101];				// description
	ITEM* items[MAX_ITEMS];		// the items in the location
}LOCATION;

typedef enum command{	// using an enum for all of the commands
	ERROR,
	N, S, E, W, IN, OUT,
	LOOK, HELP, QUIT,
	TAKE, DROP, EXAMINE,
	INVENTORY,
	END
}command;

char commands[][20] = { "error", "n", "s", "e", "w", "in", "out", "look", "help", "quit", "take", "drop", "examine", "inventory"};

int read_loc(char* filepath);						// reads in the locations
int read_items(char* filepath);						// reads in the items
command check_command(char* txt);					// checks the current command
LOCATION* direction(command dir, LOCATION* loc);	// move in a direction
void look(LOCATION* loc);							// look at the current location
void help();										// display instructions
void take(LOCATION* loc);							// take an item
void drop(LOCATION* loc);							// drop an item
void examine();										// examine an item
void check_inventory();								// look at items in inventory
int str_match(char* str_1, char* str_2);			// case insensitive string match


LOCATION locations[MAX_LOCS];
ITEM items[MAX_ITEMS];
ITEM* inventory[MAX_ITEMS];

void main() {
	char* filepath_locations = "locations.txt";
	char* filepath_items = "objects.txt";
	char input[20];						// input string
	int no_locs = read_loc(filepath_locations);		// read in from file, return how many locations are in the game
	int no_items = read_items(filepath_items);
	LOCATION* curr_loc = &locations[1];		// pointer to address of location 1
	command cmd = ERROR;
	int running = 1;

	puts("welcome to the game");
	look(curr_loc);
	do {
		printf("> ");
		scanf_s("%s", &input, 20);
		cmd = check_command(tolower(input));		// take user input and convert to command

		switch (cmd) {
			case N:
				curr_loc = direction(N, curr_loc);
				look(curr_loc);
				break;
			case S:
				curr_loc = direction(S, curr_loc);
				look(curr_loc);
				break;
			case E:
				curr_loc = direction(E, curr_loc);
				look(curr_loc);
				break;
			case W:
				curr_loc = direction(W, curr_loc);
				look(curr_loc);
				break;
			case IN:
				curr_loc = direction(IN, curr_loc);
				look(curr_loc);
				break;
			case OUT:
				curr_loc = direction(OUT, curr_loc);
				look(curr_loc);
				break;
			case LOOK:
				look(curr_loc);
				break;
			case HELP:
				help();
				break;
			case QUIT:
				puts("thanks for playing :)");
				running = 0;
				break;
			case TAKE:
				take(curr_loc);
				break;
			case DROP:
				drop(curr_loc);
				break;
			case EXAMINE:
				examine();
				break;
			case INVENTORY:
				check_inventory();
				break;
			default:
				puts("please enter a valid command");
				break;
		}
	} while (running);
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

int read_items(char* filepath) {
	FILE* fptr;
	char line[101];		// buffer for readin
	int count = 0;		// skip top two lines of headers
	int id = 0, temp = 0;

	fopen_s(&fptr, filepath, "r");

	while (fgets(line, 101, fptr) != NULL) {
		if (count < 2) {
			count++;
		}
		else {
			sscanf_s(line, "%[^\t]\t%d\t%[^\n]", &items[id].name, 50, &temp, &items[id].desc, 101);
			locations[temp].items[0] = &items[id];		// for the sake of simplicity, locations can only begin with one item
			id++;
			count++;
		}
	}

	fclose(fptr);
	return count - 1;
}

command check_command(char* txt) {
	for (int i = 0; i < (int)END; i++) {		// loop until one more than final command
		if (strcmp(txt, commands[i]) == 0) {
			return (command)i;					// typecasting to command
		}
	}
	return ERROR;
}

LOCATION* direction(command dir, LOCATION* loc) {
	switch (dir) {
		case N:
			if (loc->n != 0) {					// and north is a valid direction
				return &locations[loc->n];		// go north
			}
			else {
				printf("you can't go north from there.\n");		// otherwise, stay there
				return loc;		// this is the same for every direction
			}
			break;
		case S:
			if (loc->s != 0) {
				return &locations[loc->s];
			}
			else {
				printf("you can't go south from there.\n");
				return loc;
			}
			break;
		case E:
			if (loc->e != 0) {
				return &locations[loc->e];
			}
			else {
				printf("you can't go east from there.\n");
				return loc;
			}
			break;
		case W:
			if (loc->w != 0) {
				return &locations[loc->w];
			}
			else {
				printf("you can't go west from there.\n");
				return loc;
			}
			break;
		case IN:
			if (loc->in != 0) {
				return &locations[loc->in];
			}
			else {
				printf("you can't go in from there.\n");
				return loc;
			}
			break;
		case OUT:
			if (loc->out != 0) {
				return &locations[loc->out];
			}
			else {
				printf("you can't go out from there.\n");
				return loc;
			}
			break;
		default:
			break;
	}
}

void look(LOCATION* loc) {
	// prints the description of the current location
	int item_count = 0;

	printf("%s\n", loc->desc);
	printf("items in this location: ");
	for (int i = 0; i < MAX_ITEMS; i++) {
		if (loc->items[i] != NULL) {
			(i > 0) ? printf(", %s", loc->items[i]->name) : printf("%s", loc->items[i]->name);
			item_count++;
		}
	}
	(item_count == 0) ? printf("none.\n") : printf("\n");
}

void help() {	// prints the valid commands
	printf("i know these commands:\nn, s, e, w, in, out, look, help, quit, take, drop, examine, inventory\n");
}

void take(LOCATION* loc) {
	char input[50];
	int found = -1;

	printf("take what?\n> ");
	scanf_s(" %[^\n]s", input, 50);	// input

	// NOTE: could probably make this its own function but idrc
	for (int i = 0; i < MAX_ITEMS && found == -1; i++) {
		if (loc->items[i] != NULL) {		// if there's something in the inventory
			if (str_match(input, loc->items[i]->name)) {		// check and see if the named object is there
				found = i;
			}
		}
	}
	if (found < 0) {
		printf("that doesn't seem to be here.\n");
	}
	else {		// find where to put it
		int space = 0;	// make sure it's only the first one we're putting it in
		for (int i = 0; i < MAX_ITEMS && space != 1; i++) {
			if (inventory[i] == NULL) {
				inventory[i] = loc->items[found];
				loc->items[found] = NULL;
				space = 1;
			}
		}
		printf("you took: %s\n", inventory[found]->name);
	}
}

void drop(LOCATION* loc) {
	char input[50];
	int found = -1;
	int has_items = 0;

	for (int i = 0; i < MAX_ITEMS && has_items == 0; i++) {
		if (inventory[i] != NULL) {
			has_items = 1;
		}
	}
	if (!has_items) {
		printf("you don't have anything to drop\n");
		return;
	}

	printf("drop what?\n> ");
	scanf_s(" %[^\n]s", input, 50);

	for (int i = 0; i < MAX_ITEMS && found == -1; i++) {
		if (inventory[i] != NULL) {		// if there's something in the inventory
			if (str_match(input, inventory[i]->name)) {		// check and see if the named object is there
				found = i;
			}
		}
	}
	if (found < 0) {
		printf("you don't have that.\n");
	}
	else {		// find where to put it, i.e. see what entry in the items array is null
		int space = 0;
		for (int i = 0; i < MAX_ITEMS && space != 1; i++) {
			if (loc->items[i] == NULL) {
				loc->items[i] = inventory[found];
				inventory[found] = NULL;
				space = 1;
				printf("you dropped: %s\n", loc->items[i]->name);
			}
		}
	}
}

void examine() {
	char input[50];
	int found = 0;
	int has_items = 0;
	for (int i = 0; i < MAX_ITEMS && has_items == 0; i++) {
		if (inventory[i] != NULL) {
			has_items = 1;
		}
	}
	if (!has_items) {
		printf("you don't have anything to examine\n");
		return;
	}

	printf("examine what?\n> ");
	scanf_s(" %[^\n]s", input, 50);	// input

	for (int i = 0; i < MAX_ITEMS && found != 1; i++) {
		if (inventory[i] != NULL) {		// if there's something in the inventory
			if (str_match(input, inventory[i]->name)) {		// check and see if the named object is there
				printf("%s\n", inventory[i]->desc);			// print that object's description
				found++;
			}
		}
	}
	if (!found) {
		printf("you don't have that.\n");
	}
}

void check_inventory() {
	int item_count = 0;
	int has_items = 0;
	for (int i = 0; i < MAX_ITEMS && has_items == 0; i++) {
		if (inventory[i] != NULL) {
			has_items = 1;
		}
	}
	if (!has_items) {
		printf("you don't have anything in your inventory\n");
		return;
	}

	printf("items in inventory: ");
	for (int i = 0; i < MAX_ITEMS; i++) {
		if (inventory[i] != NULL) {
			(i > 0) ? printf(", %s", inventory[i]->name) : printf("%s", inventory[i]->name);
			item_count++;
		}
	}
	(item_count == 0) ? printf("none.\n") : printf("\n");
}

int str_match(char* str_1, char* str_2) {
	int i, j;
	char temp_str_1[50];
	char temp_str_2[50];

	for (i = 0; i < strlen(str_1); i++) {
		temp_str_1[i] = tolower(str_1[i]);
	}
	temp_str_1[i] = '\0';
	for (j = 0; j < strlen(str_2); j++) {
		temp_str_2[j] = tolower(str_2[j]);
	}
	temp_str_2[j] = '\0';

	if (strcmp(temp_str_1, temp_str_2) == 0) {
		return 1;
	}
	else {
		return 0;
	}
}
