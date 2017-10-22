#include <stdio.h>
#include <stdlib.h>

int pentagonal(int n) {
	return (n * (3 * n - 1)) / 2;
}

int is_pentagonal(int number) {
	int i = 1;
	int pentagonal_i = pentagonal(i);
	while (pentagonal_i <= number) {
		if (number == pentagonal_i)
			return 1;
		++i;
		pentagonal_i = pentagonal(i);
	}
	return 0;
}

int main(void) {
	int step = 100;
	int old_border = 1;
	int new_border = step;
	while (1) {
		for (int a = 1; a < old_border; ++a) {
			for (int b = old_border; b < new_border; ++b) {
				if (is_pentagonal(pentagonal(a) + pentagonal(b)) && is_pentagonal(abs(pentagonal(a) - pentagonal(b)))) {
					printf("Result: %d\n", abs(pentagonal(b) - pentagonal(a)));
					return 0;
				}
			}
		}
		for (int a = old_border; a < new_border; ++a) {
			for (int b = old_border; b < new_border; ++b) {
				if (is_pentagonal(pentagonal(a) + pentagonal(b)) && is_pentagonal(abs(pentagonal(a) - pentagonal(b)))) {
					printf("Result: %d\n", abs(pentagonal(b) - pentagonal(a)));
					return 0;
				}
			}
		}
		for (int a = old_border; a < new_border; ++a) {
			for (int b = 1; b < old_border; ++b) {
				if (is_pentagonal(pentagonal(a) + pentagonal(b)) && is_pentagonal(abs(pentagonal(a) - pentagonal(b)))) {
					printf("Result: %d\n", abs(pentagonal(b) - pentagonal(a)));
					return 0;
				}
			}
		}
		old_border = new_border;
		new_border += step;
	}
	return 0;
}