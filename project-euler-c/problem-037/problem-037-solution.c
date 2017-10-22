#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

int is_prime(int number, int *prime_list, int prime_list_size) {
	for (int i = 0; i < prime_list_size, prime_list[i] <= number; ++i) {
		if (number == prime_list[i])
			return 1;
		else if (number % prime_list[i] == 0)
			return 0;
	}
	return 0;
}

int ten_to_the(double power) {
	int number = 1;
	for (int i = 0; i < power; ++i)
		number *= 10;
	return number;
}

int is_trancutable_left(int number, int *prime_list, int prime_list_size) {
	while (number != 0) {
		if (!is_prime(number, prime_list, prime_list_size))
			return 0;
		number = number % ten_to_the(log10((double) number) -1);
	}
	return 1;
}

int is_trancutable_right(int number, int *prime_list, int prime_list_size) {
	while (number != 0) {
		if (!is_prime(number, prime_list, prime_list_size))
			return 0;
		number /= 10;
	}
	return 1;
}

int is_trancutable(int number, int *prime_list, int prime_list_size) {
	if (is_trancutable_left(number, prime_list, prime_list_size) && is_trancutable_right(number, prime_list, prime_list_size)) {
		return 1;
	}
	return 0;
}

int main(void) {
	int trancutable_primes_count;
	int trancutable_primes_sum = 0;
	int limit = 100;
	int already_tested_integers_border = 7;
	int *prime_array;
	for (trancutable_primes_count = 0; trancutable_primes_count < 11; ) {
		int lim = limit;
		int array_size = sieve_of_eratosthenes(&prime_array, (long long) lim);
		for (int i = 0; i < array_size; ++i) {
			if (prime_array[i] > already_tested_integers_border) {
				if (is_trancutable(prime_array[i], prime_array, array_size)) {
					trancutable_primes_sum += prime_array[i];
					trancutable_primes_count++;
				}
				if (trancutable_primes_count == 11)
					break;
			}
		}
		already_tested_integers_border = limit;
		limit *= 10;
	}
	printf("Sum = %d\n", trancutable_primes_sum);
	return 0;
}