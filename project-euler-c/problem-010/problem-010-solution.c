#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// returns 0 if no new primes are found, else returns the new prime
long long add_prime_sieve_of_eratosthenes(long long last_found_prime, int *natural_numbers_array, long long natural_numbers_array_size) {
	// find the next prime
	long long index = 0;
	if (last_found_prime != 0)
		index = last_found_prime - 1;
		
	while (last_found_prime >= natural_numbers_array[index] && index < natural_numbers_array_size)
		++index;
	// check if no prime was found
	if (index == natural_numbers_array_size)
		return -1;
	long long new_prime = natural_numbers_array[index];
	// remove entries of numbers divisible by the new prime
	for (long long i = new_prime * new_prime - 2; i < natural_numbers_array_size; i += new_prime)
		natural_numbers_array[i] = 0;
	return new_prime;
}

long long sieve_of_eratosthenes(int **prime_array, long long limit) {
	// generate an array of natural numbers
	long long natural_numbers_array_size = limit - 1;
	int *natural_numbers_array = malloc(sizeof(int) * natural_numbers_array_size);
	if (natural_numbers_array == NULL) {
		return -1; // malloc can't allocate
	}
	for (long long i = 2; i <= limit; ++i)
		natural_numbers_array[i - 2] = i;
	// extract primes from natural_numbers_array and count them
	long long prime_count = 0;
	long long new_prime = 0;
	while ((new_prime = add_prime_sieve_of_eratosthenes(new_prime, natural_numbers_array, natural_numbers_array_size)) > 0)
		++prime_count;
	// make an array of primes
	*prime_array = malloc(sizeof(long long) * prime_count);
	long long i = 0;
	long long j = 0;
	for (; i < natural_numbers_array_size; ++i) {
		if (natural_numbers_array[i] != 0)
			(*prime_array)[j++] = natural_numbers_array[i];
	}
	free(natural_numbers_array);
	return prime_count;
}

int main(int argc, char const *argv[]) {
	int limit = 2000000;
	if (argc == 2)
		limit = atoi(argv[1]);
	clock_t t;
	t = clock();
	int *primes;
	sieve_of_eratosthenes(&primes, limit);
	int i = 0;
	unsigned long long sum = 0;
	while(primes[i] != 0) {
		sum += primes[i];
		++i;
	}
	printf("Result: %llu\n", sum);
	t = clock() - t;
	double time_taken = ((double)t)/CLOCKS_PER_SEC;

	printf("The program took %f seconds to execute.\n", time_taken);
	return 0;
}
