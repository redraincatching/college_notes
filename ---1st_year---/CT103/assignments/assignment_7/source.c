#include <stdio.h>
#include <string.h>

#define pi 3.14	// i feel like this is self-explanatory

float cirque() {	// circle function
	float radius = 0.0;
	puts("enter the radius:");
	scanf_s("%f", &radius);
	float area = pi * (radius * radius);	// i get a warning when i use float for these?
	return area;
}

float tri() {		// triangle function
	float base = 0.0;
	float height = 0.0;
	puts("enter the base length:");
	scanf_s("%f", &base);
	puts("enter the vertical height:");
	scanf_s("%f", &height);
	float area = 0.5 * base * height;
	return area;
}

float rect() {	// rectangle function
	float width = 0.0;
	float height = 0.0;
	puts("enter the width:");
	scanf_s("%f", &width);
	puts("enter the height:");
	scanf_s("%f", &height);
	float area = width * height;
	return area;
}

float trap() {		// trapezium function
	float base = 0.0;
	float height = 0.0;
	puts("enter the base length:");
	scanf_s("%f", &base);
	puts("enter the height:");
	scanf_s("%f", &height);
	float area = base * height;
	return area;
}

void main() {
	char shape[20] = { "gonna be a shape" };		// name of shape to be found
	float area;

	puts("________________________________");
	puts("enter the shape that you would like to find the area of:\n(circle, triangle, rectangle, trapezium)\n(enter \"done\" if you would like to quit)");
	puts("________________________________");
	gets(shape);	// get string to be compared

	do {	

		if (!strcmp(shape, "circle")) {		// circle
			area = cirque();
			printf("the area of your circle is %0.2f metres squared\n\n", area);		
		}
		else if (!strcmp(shape, "triangle")) {		// triangle
			area = tri();
			printf("the area of your triangle is %0.2f metres squared\n\n", area);
		}
		else if (!strcmp(shape, "rectangle")) {		// rectangle
			area = rect();
			printf("the area of your recetangle is %0.2f metres squared\n\n", area);

		}
		else if (!strcmp(shape, "trapezium")) {		// trapezium
			area = trap();
			printf("the area of your trapezium is %0.2f metres squared\n\n", area);

		}
		else if (!strcmp(shape, "done")) {
			break;	// special cases, so as not to set off the "that's not a shape"
		}
		else {
			puts("\nthat's not a valid shape. please enter another\n");		// catch weird inputs
		}

		
		puts("________________________________");
		puts("enter the shape that you would like to find the area of:\n(circle, triangle, rectangle, trapezium)\n(enter \"done\" if you would like to quit)");
		puts("________________________________");
		scanf_s("%s", shape, 20);	// get string to be compared
				// this time it's a scanf, because the gets cause an issue with the \n left in the buffer after the first attempt

	} while (strcmp(shape, "done"));
}