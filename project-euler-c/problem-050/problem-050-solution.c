#include <stdio.h>
#include <stdlib.h>
#define LIM 1000000

// return 0 on true, 1 on false
int is_prime(int number, int *array) {
	int i = 0;
	while (array[i] != 0 && array[i] * array[i] <= number){
		if (number % array[i] == 0)
			return 1;
		++i;
	}
	return 0;
}

// max prime value + array for storage - returns number of primes
int generate_primes(int lim, int *array) {
	int prime_count = 0;
	for (int i = 2; i < lim; ++i) {
		if (!is_prime(i, array)) {
			array[prime_count] = i;
			++prime_count;
		}
	}
	return prime_count;
}

int array_sum(int *array, int left_index, int right_index) {
	int sum = 0;
	for ( ;left_index <= right_index; ++left_index)
		sum += array[left_index];
	return sum;
}

int main(void) {
	int lim = LIM, array[lim], terms;
	int sum = 0;
	int best_i, best_j;
	int max_terms = -1;
	int best_sum = 0;
	for (int i = 1; i < lim; ++i) array[i] = 0;
	int prime_count = generate_primes(lim, array);
	printf("%d primes generated.\n", prime_count);

	for (int i = 0; i < prime_count ; ++i) {
		sum = 0;
		for (int j = i; j < prime_count; ++j) {
			sum += array[j];
			//printf("sum = %d\n", sum);
			if (sum > 1000000) {
				sum -= array[j];
				break;
			}
			if (!is_prime(sum, array)) {
				terms = j - i + 1;
				if (terms >= max_terms) {
					max_terms = terms;
					best_sum = sum;
					best_i = i;
					best_j = j;
				}
			}
		}
	}
	printf("max_terms = %d, best_sum = %d, i = %d, j = %d\n", max_terms, best_sum, best_i, best_j);
	return 0;
}