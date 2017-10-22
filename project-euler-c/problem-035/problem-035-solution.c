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

int rotate_int(int number, int size) {
	char number_array[size];
	// get number in an array
	for (int i = 0; number != 0; ++i) {
		number_array[i] = number % 10;
		number /= 10;
	}
	// get array in order
	for (int i = 0; i < size / 2; ++i) {
		int tmp = number_array[i];
		number_array[i] = number_array[size - i - 1];
		number_array[size - i - 1] = tmp;
	}
	// rotate
	int first = number_array[0];
	for (int i = 0; i < size - 1; ++i)
		number_array[i] = number_array[i + 1];
	number_array[size - 1] = first;
	// add to ascii value for atoi
	for (int i = 0; i < size; ++i)
		number_array[i] += 48;
	return atoi(number_array);
}
int is_circular_prime(int number, int *primes, int prime_count) {
	int number_size = (int) log10(number) + 1;
	char number_array[number_size];
	// get array values
	for (int i = 0; number != 0; ++i) {
		number_array[i] = number % 10 + 48;
		number /= 10;
	}
	// mirror array
	for (int i = 0; i < number_size / 2; ++i) {
		char tmp = number_array[i];
		number_array[i] = number_array[number_size - i - 1];
		number_array[number_size - i - 1] = tmp;
	}
	// rotate array
	for (int i = 0; i < number_size; ++i) {
		char first = number_array[0];
		for (int i = 0; i < number_size - 1; ++i)
			number_array[i] = number_array[i + 1];
		number_array[number_size - 1] = first;
		int number = atoi(number_array);
		if (!is_prime(number, primes, prime_count))
			return 0;
	}
	return 1;
}

int main(void) {
	int count = 0;
	int *primes;
	int limit = 1000000;
	int prime_count = sieve_of_eratosthenes(&primes, limit);
	for (int i = 0; i < prime_count; ++i) {
		if (is_circular_prime(primes[i], primes, prime_count)) {
			++count;
		}
	}
	printf("Answer: %d\n", count);
}