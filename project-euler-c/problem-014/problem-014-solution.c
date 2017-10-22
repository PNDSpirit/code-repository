#include <stdio.h>

int collatz_terms(int number) {
	int count = 1;
	long long starting_number = number;
	while (starting_number > 1) {
		if (starting_number % 2 == 0) {
			starting_number /= 2;
		}
		else {
			starting_number *= 3;
			starting_number += 1;
		}
		count += 1;
	}
	return count;
}

int main(void) {
	int terms;
	int max_terms = 0;
	int number;
	for (int i = 1; i < 1000000; ++i) {
		terms = collatz_terms(i);
		if (terms > max_terms){
			number = i;
			max_terms = terms;
		}
	}
	printf("Answer: %d\n", number);
}