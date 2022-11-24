/*
flesch readability index
2022/03/08
please note: special characters such as É have been changed to avoid errors involving unicode not being supported
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char textbody[1000000];	// able to hold the full body of text
char line[1000];		// holds one line

void split_words(char* filepath);	// reads in the file
double compute_index();	// computes the index itself
int isvowel(char c);	// checks if vowel


void main() {
	char* filepath = "rte_article.txt";
	split_words(filepath);

	double index = compute_index();
	printf("\nthe flesch readability index of this body of text is %.4lf\n", index);
}

void split_words(char* filepath) {
	FILE* fptr;
	fopen_s(&fptr, filepath, "r");

	if (fptr != NULL) {
		textbody[0] = '\0';		// make sure this is a string
		while (fgets(line, 1000, fptr) != NULL) {
			strcat_s(textbody, 1000, line);		// cat these two together, keeping \n intact
		}
		fclose(fptr);
	}
	printf("%s\n", textbody);
}

double compute_index() {
	double syllables = 0, wordsyl = 0, words = 0, sentences = 0;
	int len;

	char* delimiters = " \n/";	// delimited by newline, /, and space
	char* next = NULL;
	char* first = strtok_s(textbody, delimiters, &next);
	while (first != NULL) {
		words++;
		len = strlen(first);	// see how many letters we have to deal with

		for (int i = 0; i < len-1 && len != 0; i++) {	// loop through each word letter by letter, count syllables
			if (isvowel(first[i])) {
				if (!isvowel(first[i + 1]) || !isalnum(first[i + 1]) && first[i + 1] != '\'' && tolower(first[len-1]) != 'e') {
					wordsyl++;
				}
			}
		}
		if (wordsyl == 0 && len != 0) {
			syllables++;		// add a single syllable to the word if can't find any
		}
		else {
			syllables += wordsyl;	// otherwise, add any syllables found (is 0 if len == 0)
			wordsyl = 0;
		}

		if (first[len-1] == '.' || first[len-1] == ':' || first[len-1] == ';' || first[len-1] == '?' || first[len-1] == '!') {
			sentences++;	// end of sentence? sentence++
		}

		first = strtok_s(NULL, delimiters, &next);
	};
	sentences++;

	double index = 206.835 - (84.6 * (syllables / words)) - (1.015 * (words / sentences));	// just the formula given
	return index;
}

int isvowel(char c) {
	c = tolower(c);
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y') {
		return 1;
	}
	else {
		return 0;
	}
}
