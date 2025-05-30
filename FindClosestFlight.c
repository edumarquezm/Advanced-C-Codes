#include <stdio.h>

// Enter a time expressed in hours and minutes, the program will display the closest plane departure at that time

void find_closest_flight(int desired_time, int* departure_time, int* arrival_time);

int main(void) {

	int hour, minutes, input_time, leaving_time, landing_time;

	printf("Enter a 24-hour time (hh:mm): ");
	scanf("%d :%d", &hour, &minutes);

	input_time = hour * 60 + minutes;

	find_closest_flight(input_time, &leaving_time, &landing_time);

	printf("The closest departure time is: %d:%.2d", leaving_time / 60, leaving_time % 60);
	printf(", arriving at: %d:%.2d", landing_time / 60, landing_time % 60);

	return 0;
}



void find_closest_flight(int desired_time, int* departure_time, int* arrival_time) {

	// Departure times (hour * 60 + minutes)
	int dt1 = 480, dt2 = 583, dt3 = 679, dt4 = 767, dt5 = 840, dt6 = 945, dt7 = 1140, dt8 = 1305;

	// Arrival times (hour * 60 + minutes) 
	int at1 = 616, at2 = 712, at3 = 811, at4 = 900, at5 = 968, at6 = 1075, at7 = 1280, at8 = 1438;


	// FORMULA TO FIND MIDPOINT ->  m =	 dt1  + (dt2 - dt1) / 2

	if (desired_time <= dt1 + (dt2 - dt1) / 2) {
		*departure_time = dt1;
		*arrival_time = at1;
	}
	
	else if (desired_time <= dt2 + (dt3 - dt2) / 2) {
		*departure_time = dt2;
		*arrival_time = at2;
	}
	
	else if (desired_time <= dt3 + (dt4 - dt3) / 2) {
		*departure_time = dt3;
		*arrival_time = at3;
	}
	
	else if (desired_time <= dt4 + (dt5 - dt4) / 2) {
		*departure_time = dt4;
		*arrival_time = at4;
	}
	
	else if (desired_time <= dt5 + (dt6 - dt5) / 2) {
		*departure_time = dt5;
		*arrival_time = at5;
	}
	
	else if (desired_time <= dt6 + (dt7 - dt6) / 2) {
		*departure_time = dt6;
		*arrival_time = at6;
	}
	
	else if (desired_time <= dt7 + (dt8 - dt7) / 2) {
		*departure_time = dt7;
		*arrival_time = at7;
	}
	
	else {
		*departure_time = dt8;
		*arrival_time = at8;
	}
}
