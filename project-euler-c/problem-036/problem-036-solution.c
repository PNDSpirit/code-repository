#include <stdio.h>

int is_array_palindrome(int *array, int size) {
	for (int i = 0; i < size / 2; ++i) {
		if (!(array[i] == array[size - i - 1]))
			return 0; // is not palindrome
	}
	return 1; // is palindrome
}

int is_palindrome_binary(int number) {
	int digits[32];
	for (int i = 0; i < 32; ++i)
		digits[i] = -1;
	int i = 0;
	while (number != 0) {
		digits[i++] = number % 2;
		number /= 2;
	}
	if (is_array_palindrome(digits, i))
		return 1; // is palindrome
	return 0; // is not palindrome
}

int is_palindrome_decimal(int number) {
	int digits[10];
	for (int i = 0; i < 10; ++i)
		digits[i] = -1;
	int i = 0;
	while (number != 0) {
		digits[i++] = number % 10;
		number /= 10;
	}
	if (is_array_palindrome(digits, i))
		return 1; // is palindrome
	return 0; // is not palindrome
}

int is_palindrome_binary_and_decimal(int number) {
	if (is_palindrome_decimal(number) && is_palindrome_binary(number))
		return 1; // is palindrome in binary and decimal
	return 0; // is not palindrome in binary and decimal
}

int main(void) {
	unsigned int sum = 0;
	for (int i = 0; i < 1000000; ++i) {
		if (is_palindrome_binary_and_decimal(i))
			sum += i;
	}
	printf("Sum = %d\n", sum);
	return 0;
}