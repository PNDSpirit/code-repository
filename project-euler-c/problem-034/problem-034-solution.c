#include <stdio.h>

int factorial(int number) {
	int result = 1;
	switch (number) {
		case 1: return 1; break;
		case 2: return 2; break;
		case 3: return 6; break;
		case 4: return 24; break;
		case 5: return 120; break;
		case 6: return 720; break;
		case 7: return 5040; break;
		case 8: return 40320; break;
		case 9: return 362880; break;
		default: 
			for (int i = 1; i <= number; ++i)
				result *= i;
			return result;
			break;
	}
}

int sum_of_factorials(int num) {
	int sum = 0;
	while (num != 0) {
		sum += (factorial(num % 10));
		num /= 10;
	}
	return sum;
}

int main(void) {
	int lim = 7 * factorial(9);
	int sum = 0;
	for (int i = 10; i < lim; ++i) {
		if (i == sum_of_factorials(i))
			sum += i;
	}
	printf("Sum = %d\n", sum);
	return 0;
}