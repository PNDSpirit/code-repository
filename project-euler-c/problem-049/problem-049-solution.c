#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define LIMIT 10000

int is_prime(int number, int *array) {
	int i = 0;
	while (array[i] != 0 && array[i] < number) {
		if (number % array[i] == 0)
			return 1;
		++i;
	}
	return 0;
}

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

void insertion_sort_swap(int *x, int *y) {
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

int insertion_sort(int *array, int array_size) {
	for (int i = 1; i < array_size; ++i) {
		int j = i;
		while (j > 0 && array[j] < array[j - 1]) {
			insertion_sort_swap(array + j, array + j - 1);
			--j;
		}
	}
}

// return 0 on true, 1 on false
int are_permutations(int a, int b) {
	int a_size = log10(a) + 1;
	int b_size = log10(b) + 1;
	if (a_size != b_size)
		return 1;
	int a_array[a_size];
	int b_array[b_size];
	for (int i = 0; i < a_size; ++i, a /= 10, b /= 10) {
		a_array[i] = a % 10;
		b_array[i] = b % 10;
	}
	insertion_sort(a_array, a_size);
	insertion_sort(b_array, b_size);
	for (int i = 0; i < a_size; ++i)
		if (a_array[i] != b_array[i])
			return 1;
	return 0;


}

int main(void) {
	int lim = LIMIT;
	int temp_array[lim];
	for (int i = 0; i < lim; ++i) temp_array[i] = 0;
	int prime_count = generate_primes(lim, temp_array);
	int array[prime_count];
	for (int i = 0; i < prime_count; ++i) {
		array[i] = temp_array[i];
	}
	// for (int i = 0; i < 1000; ++i)
	// 	printf("%d\n", array[i]);
	// return 0;
	for (int i = 0; i < prime_count; ++i) {
		for (int j = i + 1; j < prime_count; j++) {
			int temp = (array[j] * 2) - array[i];
			if (!is_prime(temp, array) && !are_permutations(array[j], array[i]) && !are_permutations(temp, array[j]))
				if (array[i] != 1487)
					printf("Result: %d%d%d\n", array[i], array[j], array[j] * 2 - array[i]);
		}
	}

	return 0;
}