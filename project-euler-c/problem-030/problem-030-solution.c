#include <stdio.h>

int power(int number, int power) {
	int val = 1;
	for (int i = 0; i < power; ++i)
		val *= number;
	return val;
}

int sum_of_digits_to_the_fifth_power(int number) {
	int sum = 0;
	while (number != 0) {
		sum += power(number % 10, 5);
		// printf("number = %d, digit = %d, digit^5 = %d, sum = %d\n", number, number % 10, power(number % 10, 5), sum);
		number /= 10;
	}
	return sum;
}

int main(void) {
	int limit = 6 * (9 * 9 * 9 * 9 *9);
	int sum;
	for (int i = 2; i <= limit; ++i) {
		if (i == sum_of_digits_to_the_fifth_power(i)) {
			sum += i;
		}
	}
	printf("Answer: %d\n", sum);

	return 0;
}