/*
assignment 6
eidhne kennedy
21347021
2021/11/02
*/
#include <stdio.h>

void main() {
	int user_ratings[21];	// rating array
	float avg_rat = 0;		// average rating
	float rat_freq[5] = { 0,0,0,0,0 };		// frequency of ratings
	float rating_percent[5];	// rating percent

	for (int i = 0; i < 21; i++) {	// loop 21 times
		printf("enter the rating for movie %d: ", i+1);
		scanf_s("%d", &user_ratings[i]);

		switch (user_ratings[i]) {		// switch case to assign values, and add to average
			case 1:					
				rat_freq[0]++;		// could use a function for this?
				avg_rat += 1;	// but not sure how to change the global variables in a function
				break;
			case 2:
				rat_freq[1]++;
				avg_rat += 2;
				break;
			case 3:
				rat_freq[2]++;
				avg_rat += 3;
				break;
			case 4:
				rat_freq[3]++;
				avg_rat += 4;
				break;
			case 5:
				rat_freq[4]++;
				avg_rat += 5;
				break;
			default:
				printf("that is not a valid input, please enter a rating from 1 - 5 stars.\n");
				i--;	// make sure 21 inputs are entered
				break;
		}
	}

	avg_rat = avg_rat / 21;		// find average
	printf("\nthe average rating was: %0.1f\n\n", avg_rat);

	printf("----------------\nrating frequency\n----------------\n");	// starting the frequency of ratings

	for (int i = 0; i < 5; i++) {
		printf("%d star \t", i+1);	// kind of star
		for (int j = 0; j < rat_freq[i]; j++) {
			printf("*");	// loop through and print as necessary
		}
		printf("\t%0.0f\n", rat_freq[i]);	// number
	}
	printf("\n----------------\n");
	printf("rating percent");
	printf("\n----------------\n");

	for (int i = 0; i < 5; i++) {	// find the percentage frequency of each
		rating_percent[i] = (rat_freq[i] / 21) * 100;
		printf("%d star \t", i + 1);
		for (int j = 0; j < rating_percent[i]; j++) {
			printf("*");	// loop through and print as necessary
		}
		printf("\t%0.1f%%\n", rating_percent[i]);
	}

}
