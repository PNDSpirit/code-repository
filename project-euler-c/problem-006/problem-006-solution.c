#include <stdio.h>

int main(void) {
	unsigned long long sum1 = 0;
	unsigned long long sum2 = 0;
	unsigned long long diff = 0;
	for (int i = 1; i <= 100; ++i) {
		sum1 += i * i;
		sum2 += i;
	}
	sum2 *= sum2;
	diff = sum2 - sum1;
	printf("Answer: %llu\n", diff);
}