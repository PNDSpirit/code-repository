#include <stdio.h>

int next_chain_piece(int number) {
	int new_sum = 0;
	while (number != 0) {
		int digit = number % 10;
		new_sum += digit * digit;
		number /= 10;
	}
	return new_sum;
}

int chain_result(int number) {
	while (1) {
		number = next_chain_piece(number);
		if (number == 89 || number == 1)
			return number;
	}
}

int main(void) {
	int counter = 0;
	for (int i = 1; i < 10000000; ++i) {
		int result = chain_result(i);
		if (result == 89)
			++counter;
	}
	printf("Answer: %d\n", counter);
}