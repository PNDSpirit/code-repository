#include <stdio.h>

int is_pythagorean_triplet (int a, int b, int c) {
	if ((a * a + b * b) == c * c)
		return 0;
	return 1;
}

int main (void) {
	int a, b, c, product;
	for (a = 1; a < 1000; ++a) {
		for (b = 1; b < 1000; ++b) {
			c = 1000 - (a + b);
			if (c > 0 && !is_pythagorean_triplet(a, b, c)) {
				product = a * b * c;
				printf("Answer: %d\n", product);
				return 0;
			}
		}
	}
	return 1;
}