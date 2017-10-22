#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long add_prime_sieve_of_eratosthenes(long long last_found_prime, int *natural_numbers_array, long long natural_numbers_array_size) {
	long long index = 0;
	if (last_found_prime != 0)
		index = last_found_prime - 1;
		
	while (last_found_prime >= natural_numbers_array[index] && index < natural_numbers_array_size)
		++index;
	if (index == natural_numbers_array_size)
		return -1;
	long long new_prime = natural_numbers_array[index];
	for (long long i = new_prime * new_prime - 2; i < natural_numbers_array_size; i += new_prime)
		natural_numbers_array[i] = 0;
	return new_prime;
}

long long sieve_of_eratosthenes(int **prime_array, long long limit) {
	long long natural_numbers_array_size = limit - 1;
	int *natural_numbers_array = malloc(sizeof(int) * natural_numbers_array_size);
	if (natural_numbers_array == NULL) {
		return -1;
	}
	for (long long i = 2; i <= limit; ++i)
		natural_numbers_array[i - 2] = i;
	long long prime_count = 0;
	long long new_prime = 0;
	while ((new_prime = add_prime_sieve_of_eratosthenes(new_prime, natural_numbers_array, natural_numbers_array_size)) > 0)
		++prime_count;
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

int can_be_expressed_as_a_square(int number) {
	int i = 1;
	int i_i = 1;
	while (i_i <= number) {
		if (number == i_i)
			return 1;
		++i;
		i_i = i * i;
	}
	return 0;
}

int can_be_expressed_as_2x_a_square(int number) {
	if (number % 2 != 0)
		return 0;
	if (can_be_expressed_as_a_square(number / 2))
		return 1;
	return 0;
}

int number_matches_goldbachs_other_conjecture(int number, int *primes, int prime_list_size) {
	for (int i = 0; primes[i] < number; ++i) {
		if (can_be_expressed_as_2x_a_square(number - primes[i]))
			return 1;
	}
	return 0;
}

int main(void) {
	int lower_test_limit = 2;
	int upper_test_limit = 100;
	int smallest_number = 0;
	while (!smallest_number) {
		int *primes;
		int primes_count = sieve_of_eratosthenes(&primes, upper_test_limit);
		for (int i = lower_test_limit; i < upper_test_limit; ++i) {
			if (!is_prime(i, primes, primes_count) && i % 2 != 0) {
				if (!number_matches_goldbachs_other_conjecture(i, primes, primes_count)) {
					smallest_number = i;
					break;
				}
			}
		}
		lower_test_limit = upper_test_limit;
		upper_test_limit *= 10;
	}
	printf("Result: %d\n", smallest_number);
	return 0;
}