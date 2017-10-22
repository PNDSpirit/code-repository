#include <stdio.h>

int main(void) {
	long a = 1; long b = 1; long sum = 0;
	while (a < 4000000 && b < 4000000) {
		a += b; 
		if (a % 2 == 0)
			sum += a;
		b += a;
		if (b % 2 == 0)
			sum += b;
	}
	printf("Answer: %d\n", sum);
}