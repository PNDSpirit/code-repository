#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int sieve_of_sundaram(int **primes, int limit) {
	int new_limit = (limit - 1) / 2;
	char *array = malloc(new_limit);
	for (int i = 0; i < new_limit; ++i) {
		array[i] = 0;
	}
	// sieve out the matrix
	int i = 1;
	int j = i;
	while (2 * i * j + i + j <= new_limit) {
		while(2 * i * j + i + j <= new_limit) {
			array[2 * i * j + i + j - 1] = 1;
			++j;
		}
		++i;
		j = i;
	}
	// count the primes
	int prime_count = 0;
	for (int i = 0; i < new_limit; ++i) {
		if (array[i] == 0) {
			++prime_count;
		}
	}
	// fill in primes[] with the primes
	*primes = malloc(++prime_count * sizeof(int));
	i = 0;
	*primes[i++] = 2;
	for (int j = 0; j < new_limit; ++j) {
		if (array[j] == 0) {
			(*primes)[i++] = j * 2 + 3;
		}
	}
	return prime_count;
}

int main(int argc, char const *argv[]) {
	int limit = 100;
	if (argc == 2)
		limit = atoi(argv[1]);

	clock_t t;
	t = clock();

	int *primes;
	int prime_count = sieve_of_sundaram(&primes, limit);

	t = clock() - t;
	double time_taken = ((double)t)/CLOCKS_PER_SEC;
	printf("The program took %f seconds to execute.\n", time_taken);
	printf("It computed %d primes, %f primes per second\n", prime_count, prime_count / time_taken);
	return 0;
}