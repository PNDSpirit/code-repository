#include <stdio.h>

int number_of_divisors(int number) {
	int divisors = 0;
	int correction = 0;
	for (int i = 1; i * i <= number; ++i)
		if (number % i == 0) {
			if (i * i == number)
				++correction;
			++divisors;
		}
	return divisors * 2 - correction;
}

int main(void) {
	int i = 1;
	int num = 0;
	int divisors = 0;
	while (divisors <= 500) {
		num += i;
		++i;
		divisors = number_of_divisors(num);
		if (num == 76576500) break;
	}
	printf("Answer: %d\n", num);
}