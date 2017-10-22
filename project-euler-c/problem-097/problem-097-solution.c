#include <stdio.h>
#define SIZE 11
#define BASE 10

int multiply_array(int *array, int array_size, int factor, int base) {
	for (int i = array_size - 1; i > 0; --i)
		array[i] *= factor;
	for (int i = array_size - 1; i > 0; --i) {
		array[i - 1] += array[i] / base;
		array[i] -= (array[i] / base) * base;
	}
	if (array[0] > base - 1)
		return 1; // array too small
	else
		return 0;
}

int main(void) {
	int array[SIZE];
	for (int i = 0; i < SIZE; ++i)
		array[i] = 0;
	array[SIZE - 1] = 1;
	for (int i = 0; i < 7830457; ++i)
		multiply_array(array, SIZE, 2, BASE);
	multiply_array(array, SIZE, 28433, BASE);
	array[SIZE - 1] += 1;
	printf("Result: ");
	for (int i = SIZE - 10; i < SIZE; ++i)
		printf("%d", array[i]);
	printf("\n");
	return 0;
}
