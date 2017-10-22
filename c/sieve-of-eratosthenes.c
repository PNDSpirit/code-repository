#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int sieve_of_eratosthenes(int **primes, int limit) {
	char *array = malloc(limit);
	for (int i = 0; i < limit; ++i) {
		array[i] = 0;
	}
	for (int i = 2; i < limit; ++i) {
		if (i * i > limit)
			break;
		while (array[i - 1] == 1) {
			++i;
			printf("i = %d\n", i);
		}

		for (int j = i * i; j <= limit; j += i) {
			array[j - 1] = 1;
		}
	}
	int primes_count = 0;
	for (int i = 1; i < limit; ++i) {
		if (array[i] == 0)
			++primes_count;
	}
	*primes = malloc(primes_count * sizeof(int));
	int j = 0;
	for (int i = 1; i < limit; ++i) {
		if (array[i] == 0)
			(*primes)[j++] = i + 1;
	}
	return primes_count;
}

int main(int argc, char const *argv[]) {
	int limit = 2000000;
	if (argc == 2)
		limit = atoi(argv[1]);
	clock_t t;
	t = clock();
	unsigned long long primes_sum = 0;
	int *primes;
	int prime_count = sieve_of_eratosthenes(&primes, limit);
	for (int i = 0; i < prime_count; ++i) {
		primes_sum += primes[i];
	}
	printf("Result: %llu\n", primes_sum);
	t = clock() - t;
	double time_taken = ((double)t)/CLOCKS_PER_SEC;

	printf("The program took %f seconds to execute.\n", time_taken);
	return 0;
}