#include <stdio.h>
#define SIZE 20

int get_prime_factors(int number, int *result) {
	int array[SIZE];
	// get the array to zeroes only
	int counter = 0;
	for (int i = 0; i < SIZE; ++i) {
		array[i] = 0;
		result[i] = 0;
	}
	// get factors
	while (number > 1) {
		for (int i = 2; i <= number; ++i) {
			if (number % i == 0) {
				array[counter++] = i;
				number /= i;
				i = 1;
			}
		}
	}
	// get only unique factors
	int previous_factor = 0;
	int j = 0;
	for (int i = 0; array[i] != 0; ++i) {
		if (previous_factor != array[i]) {
			result[j++] = array[i];
			previous_factor = array[i];
		}
		else {
			result[j - 1] *= previous_factor;
		}
	}
	return j;
}

void print_array(int *array) {
	for (int i = 0; i < SIZE; ++i) {
		if (array[i] == 0)
			break;
		printf("%d, ", array[i]);
	}
}
// two_arrays_have_common_elements
int TAHCE(int *array1, int *array2) {
	int i = 0; 
	int j = 0;
	while (array1[i] != 0 || array2[j] != 0) {
		if (array1[i] > array2[j] && array2[j] != 0) {
			++j;
		}
		else if (array1[i] < array2[j] && array1[i] != 0) {
			++i;
		}
		else if (array1[i] == 0 && array2[j] == 0) {
			return 0; // no common element
		}
		else if (array1[i] == array2[j]) {
			return 1; // common element
		}
		else if (array1[i] == 0)
			j++;
		else if (array2[j] == 0)
			i++;
	}
}

int the_four_arrays_have_no_common_elements(int *array1, int *array2, int *array3, int *array4) {
	if (!(TAHCE(array1, array2)) && !(TAHCE(array1, array3)) && !(TAHCE(array1, array4)) && !(TAHCE(array2, array3)) && !(TAHCE(array2, array4)) && !(TAHCE(array3, array4)))
		return 1;
	return 0;
}

int get_the_number(void) {
	int factors1[SIZE];
	int factors2[SIZE];
	int factors3[SIZE];
	int factors4[SIZE];
	for (int i = 644; ; ++i) {
		int factors_count1 = get_prime_factors(i, factors1);
		int factors_count2 = get_prime_factors(i + 1, factors2);
		int factors_count3 = get_prime_factors(i + 2, factors3);
		int factors_count4 = get_prime_factors(i + 3, factors4);
		if (factors_count1 != 4 || factors_count2 != 4 || factors_count3 != 4 || factors_count4 != 4) {
			// printf("%d\n", i);
			continue;
		}
		if (the_four_arrays_have_no_common_elements(factors1, factors2, factors3, factors4))
			return i;
	}
}

int main(void) {
	printf("Result: %d\n", get_the_number());
	return 0;
}