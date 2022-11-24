/*
assignment 8
éidhne kennedy
21347021
2021/11/16
*/

#include <stdio.h>
#include <string.h>
#include <math.h>		// for round()
#define barrel_volume 0.48

float pool_volume(float l, float w, float d) {
	float volume = l * w * d;
	return volume;		// all volumes are in m^3
}

void pool_mass(float v) {
	float mass = v * 1000;
	printf("\nthe mass of the water in this pool is %0.2f kg", mass);
}

int barrels(float v) {
	int barrels = round(v / barrel_volume);		// rounding was kind of dodgy with just dividing into an int, so, round()
	return barrels;
}

void main() {
	char student[9];	// our ids are 8 digits

	printf("enter your student id: ");
	scanf_s("%s", student, 9);

	float volume = pool_volume((student[5] - '0'), (student[6] - '0'), (student[7] - '0'));	// type casting
	printf("the pool's volume is %0.2f metres cubed", volume);

	pool_mass(volume);

	int barr = barrels(volume);
	printf("\nthis amount of water could fill %d barrels\n\n", barr);

}
