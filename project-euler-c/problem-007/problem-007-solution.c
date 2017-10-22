#include <stdio.h>
#define LIM 100001

int is_prime(int num, int primes[]) {
	for (int i = 0; primes[i] != 0; ++i) {
		if (num % primes[i] == 0)
			return 1;
	}
	return 0;
}

int main(void) {
	int primes[LIM];
	for (int i = 0; i < LIM; ++i) primes[i] = 0;
	int num = 2;
	int current = 0;
	while (primes[LIM - 1] == 0) {
		if (!is_prime(num, primes)) {
			primes[current] = num;
			++current;
		}
		++num;
	}
	printf("Answer: %d\n", primes[LIM - 1]);
}