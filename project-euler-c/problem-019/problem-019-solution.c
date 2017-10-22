#include <stdio.h>
// declarations for do_something()
int monthsLength[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

// declarations for do_something about the current problem
int currentDay = 1;
int currentMonth = 1;
int currentYear = 1901;

// counters
int global_counter = 1;
int sundays = 0;

// return 1 on true; return 0 on false
int is_leap_year(int year) {
	if (year % 400 == 0) return 1;
	else if (year % 100 == 0) return 0;
	else if (year % 4 == 0) return 1;
	else return 0;
}

int do_something(void) {
	while(currentYear < 2001) {
		// <debug>
		if (currentDay == 1 && global_counter % 7 == 6)
		printf("%03d. Date: %02d.%02d.%04d. Day of the week: %d\n", sundays, currentDay, currentMonth, currentYear, global_counter % 7 + 1);
		// </debug>

		if (global_counter % 7 == 6 && currentDay == 1)
			++sundays;
		++global_counter;

		if (currentMonth == 12 && currentDay == monthsLength[currentMonth]) {
			currentDay = 1;
			currentMonth = 1;
			currentYear++;
		}
		else if (currentMonth == 2 && currentDay == 28 && is_leap_year(currentYear)) {
			currentDay++;
		}
		else if (currentMonth == 2 && currentDay == 29) {
			currentDay = 1;
			currentMonth++;
		}
		else if (currentDay == monthsLength[currentMonth]) {
			currentDay = 1;
			currentMonth++;
		}
		else {
			currentDay++;
		}
	}
	return 0;
}

int main(void) {
	do_something();
	printf("Sundays: %d\n", sundays);

	return 0;
}