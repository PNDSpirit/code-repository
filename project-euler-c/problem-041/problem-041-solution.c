#include <stdio.h>

int num_length(int number) { 
	int length = 0;
	while (number != 0) {
		++length;
		number /= 10;
	}
	return length;
}

int is_prime(int n) {
	if (n == 2) return 1;
	if (n % 2 == 0) return 0;
	if (n < 9) return 1;
	if (n % 3 == 0) return 0;
	int counter = 5;
	while ((counter * counter) <= n) {
		if (n % counter == 0) return 0;
		if (n % (counter + 2) == 0) return 0;
		counter += 6;
	}
	return 1;
}

int is_pandigital(int number) {
	int length = num_length(number);
	int array[length];
	for (int i = 0; i < length; ++i) {
		array[i] = 1251;
	}
	for (int i = 0; i < length; ++i) {
		int current_digit = number % 10;
		if (array[current_digit - 1] == 1251)
			array[current_digit - 1] = 12;
		else
			return 0;
		number /= 10;
	}
	return 1;
}

int main(int argc, char const *argv[]) {
	for (int i = 7654321; ; --i) {
		// 1-8 and 1-9 are divisible by 3
		if (is_prime(i) && is_pandigital(i)) {
			printf("Result: %d\n", i);
			return 0;
		}
	}
	return 0;
}