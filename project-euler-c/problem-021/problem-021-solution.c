#include <stdio.h>
#define LIMIT 10000

int sum_of_divisors(int number) {
	int sum = 1;
	for (int i = 2; i * i <= number; ++i) {
		if (number % i == 0) {
			sum += i;
			int mirror = number / i;
			if (mirror != i)
				sum += mirror;
		}
	}
	return sum;
}

int is_amicable(int number) {
	int divisors = sum_of_divisors(number);
	if (sum_of_divisors(divisors) == number && number != divisors)
		return 0;
	return 1;
}

int main(void) {
	int sum = 0;
	for (int i = 2; i < LIMIT; ++i) {
		if (!is_amicable(i)) {
			printf("added %d\n", i);
			sum += i;
		}
	}
	printf("sum = %d\n", sum);
	return 0;
}
