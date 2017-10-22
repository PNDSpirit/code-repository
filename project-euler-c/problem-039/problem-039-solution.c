#include <stdio.h>

int is_right(int a, int b, int c) {
	if ((a * a + b * b) == (c * c))
		return 0; // is right
	return 1;
}

int main(void) {
	int array[1000];
	for (int i = 0; i < 1000; ++i)
		array[i] = 0;
	for (int c = 1; c < 500; ++c) {
		for (int b = 1; b < c; ++b) {
			for (int a = 1; a < c; ++a) {
				if (!is_right(a, b, c)) {
					if ((a + b + c) > 1000)
						break;
					++array[a + b + c - 1];
				}
			}
		}
	}

	int max_index = 0;
	for (int i = 0; i < 1000; ++i) {
		if (array[i] > array[max_index])
			max_index = i;
	}
	printf("Result: %d\n", max_index + 1);
	return 0;
}