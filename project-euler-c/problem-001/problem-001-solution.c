#include <stdio.h>

int main(void) {
	int sum;
	for (int i = 0; i < 1000; ++i) {
		if (i % 5 == 0 || i % 3 == 0)
			sum += i;
	}
	printf("Answer: %d\n", sum);
}