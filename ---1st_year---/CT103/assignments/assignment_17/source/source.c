#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "colours.h"

void read_dict();														// reads the dictionary file and stores it in an array
void not_wordle(char word[]);											// actually does the work
void display(char answer[], char guessed[], int size);					// displays everything
int check_letter(char word[], char guessed[], int size, char letter);	// checks to see if the guess is correct


char dict[100000][50];		// dictionary array
int filled_words = 0;		// how many words are actually in the dict

void main() {
	srand(time(NULL));		// randomise

	read_dict(dict);		// read in from file
	not_wordle(dict[(rand() % filled_words)]);		// pick a random word, and pass to not_wordle(tm)

}

void read_dict() {
	FILE* fptr;
	int i = 0, len = 0;
	fopen_s(&fptr, "dictionary.txt", "r");		// normal file stuff, nothing to see here

	if (fptr != NULL) {
		char line[50];

		while (!feof(fptr)) {
			fgets(line, 50, fptr);		// fgets it in
			len = strlen(line);

			if (len > 4 && len < 9) {
				strcpy_s(&dict[i], 50, line);		// between 5 and 7 letters (wonky because of \0 char
				i++;
			}
		}
		fclose(fptr);
	}

	filled_words = i;	// note: i is currently one greater than the largest index
}

void not_wordle(char word[]) {
	int correct = 0;			// bool
	int guess = 1;				// current guess that we're on
	int no_guessed = 0;			// how many diffferent characters have been tried
	int in_word;				// another bool
	int len = strlen(word);		// len goodman
	int empty = len-1;			// how many dashes are left in the answer array

	char letter;				// ...
	char guessed[50];			// letters that have been guessed
	char answer[10] = { 0 };	// the dashes/letters array


	for (int i = 0; i < len - 1; i++) {
		answer[i] = '-';			// initialise
	}

	answer[len] = '\0';				// make_string()
									// probably could have done some smoother stuff with pointers, but oh well

	while (!correct) {
		in_word = 0;
		display(answer, guessed, no_guessed+1);		// display it

		printf("guess #%d:\n>", guess);				// ask for input
		guess++;

		scanf_s(" %c", &letter, 1);
		in_word = check_letter(word, guessed, len, letter);

		if (in_word == 1) {
			for (int i = 0; i < len; i++) {
				if (word[i] == letter) {		// check if the letter is in the word
					answer[i] = letter;			// if so, reduce empty, and put that letter into the answer array
					empty--;
				}
			}
		}
		else if (in_word == -1) {
			guess--;		// try again
		}
		else {
			guessed[no_guessed] = letter;
			no_guessed++;
			for (int i = 0; i < no_guessed; i++) {
				printf("%c", guessed[i]);
			}
		}

		if (empty == 0) {
			correct = 1;
		}
	}

	printf("the word was %s\nguessed in %d attempts.", word, guess - 1);	// and end
}

void display(char answer[], char guessed[], int size) {
	system("cls");				// clear screen. note: _very_ platform and compiler dependent
	console_cyan();				// my header file is handy :)
	puts("not wordle(tm)");
	console_white();
	printf("%s\n", answer);		// print out the dashes or letters guessed

	for (int i = 0; i < size-1; i++) {
		console_red();
		printf("%c ", guessed[i]);		// print the checked characters
	}
	console_reset();
	printf("\n");
}


int check_letter(char word[], char guessed[], int size, char letter) {
	int already_guessed = 0;
	for (int i = 0; i < size && !already_guessed; i++) {
		if (guessed[i] == letter) {
			already_guessed = 1;		// just iterating through and making sure it's a new char
		}
	}

	if (already_guessed) {
		return -1;
	}
	else {
		for (int i = 0; i < size; i++) {
			if (word[i] == letter) {
				return 1;		// is it in there?
			}
		}
	}

	return 0;
}
