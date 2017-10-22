#include <stdio.h>

int is_palindrome(int number) {
	int reverse = 0;
	int temp = number;
	while (number != 0) {
		reverse = reverse * 10 + number % 10;
		number /= 10;
	}
	if (temp == reverse)
		return 0;
	return 1;
}

int main(void) {
	int number;
	int max;
	for (int i = 100; i < 1000; ++i) {
		for (int j = 100; j < 1000; ++j) {
			number = i * j;
			if ((!is_palindrome(number)) && number > max)
				max = number;
		}
	}
	printf("Answer: %d", max);
	return 0;
}