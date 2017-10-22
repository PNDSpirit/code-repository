#include <stdio.h>
#include <string.h>
#define NUMBER 600851475143

int is_prime(unsigned long long number) {
	for (int i = 2; i * i < number; ++i) {
		if (number % i == 0)
			return 1;
	}
	return 0;
}

int main(void) {
	unsigned long long number = NUMBER;
	unsigned long long max;
	for (int i = 2; i * i < number; ++i) {
		if (!is_prime(i)){
			if (number % i == 0 && i > max)
				max = i;
		}
	}
	printf("Answer: %llu\n", max);
}
