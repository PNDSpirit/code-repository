#include <stdio.h>

int divisible_by_all(int number) {
	for (int i = 2; i <= 20; i++)
		if (number % i != 0)
			return 1;
	return 0;
}

int main(void) {
	int i = 1;
	while (1) {
		if (!divisible_by_all(i))
			break;
		++i;
	}
	printf("Answer: %d\n", i);
}