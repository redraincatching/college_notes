/*
assignment 9
éidhne kennedy - 21347021
2021/11/23
*/
#include <stdio.h>
#include <math.h>
#define day_rate 23.9
#define night_rate 12.6

int hour = 0;	// don't want to have to convert back
int minute = 0;


float in_time() {
	float out_time = 0.0;
	printf("enter the current hour: ");
	scanf_s("%d", &hour);
	printf("enter the current minute: ");
	scanf_s("%d", &minute);
	if (minute >= 60) {		// hours just go round, but if minutes are more than 60, hours go up that much
		hour += (minute - minute % 60) / 60;
		out_time = (hour % 24) + ((float)(minute % 60) / 60);
	}
	else {	// else just go
		out_time = (hour % 24) + ((float)(minute % 60) / 60);
	}
	return out_time;
}

int round_time(float in_time) {
	int out_time = ceil(in_time);
	return out_time;
}

float e_price(int hour) {
	return (hour >= 0 && hour <= 8) ? day_rate : night_rate;
}

void display(float price, int time) {
	int mod_hour = hour % 24;
	int mod_minute = minute % 60;
	(mod_minute > 9) ? printf("the time is %d, or %d:%dh\nthe current electricity rate is %0.1f c/kWh\n", time, mod_hour, mod_minute, price) : printf("the time is %d, or %d:0%dh\nthe current electricity rate is %0.1f c/kWh\n", time, mod_hour, mod_minute, price);
}

void main() {	// time
	float time = in_time();
	display(e_price(round_time(time)), round_time(time));
}
