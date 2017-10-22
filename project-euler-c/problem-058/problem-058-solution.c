#include <stdio.h>
#include <stdlib.h>

int is_prime(int n) {
	if (n == 2) return 1;
	if (n % 2 == 0) return 0;
	if (n < 9) return 1;
	if (n % 3 == 0) return 0;
	int counter = 5;
	while ((counter * counter) <= n) {
		if (n % counter == 0) return 0;
		if (n % (counter + 2) == 0) return 0;
		counter += 6;
	}
	return 1;
}


int main(void) {
	int increment = 0;
	int primes = 0;
	int composites = 0;
	int current_number = 1;
	while (primes * 9 >= composites) {
		increment += 2;
		for (int i = 0; i < 3; ++i) {
			current_number += increment;
			// if (is_prime(current_number, primes_array, primes_count)) {
			if (is_prime(current_number)) {
				// printf("%d is a prime\n", current_number);
				++primes;
			}
			else {
				// printf("%d is not a prime\n", current_number);
				++composites;
			}
		}
		current_number += increment;
		composites++;
		// printf("Layer %d: %d : %d\n", increment / 2, primes, composites);
	}
	printf("Result: %d\n", increment - 1);
}