#include <stdio.h>

unsigned long long pentagonal(unsigned long long number) {
	unsigned long long i;
	for (i = 166; i * (3 * i - 1) / 2 <= number; ++i) {
		if (i * (3 * i - 1) / 2 == number) {
			return i;
		}
	}
	return 0;
}

int main(void) {
	unsigned long long test;
	for (unsigned long long i = 144; 1; ++i) {
		test = i * (2 * i - 1);
		if (pentagonal(test)) {
			printf("Answer: %llu\n", test);
			break;
		}
	}
	return 0;
}