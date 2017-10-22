#include <stdio.h>
#define SIZE 2500
#define BASE 10

int max(int a, int b) {
	if (a > b)
		return a;
	else 
		return b;
}

int print_array(int *array, int array_size) {
	int i = 0;
	while (array[i] == 0)
		++i;
	for ( ; i < array_size; ++i)
		printf("%d", array[i]);
	return 0;
}

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
	for (int i = 1; i <= 100; ++i) {
		multiply_array(array, SIZE, i, BASE);
		// print_array(array, SIZE);
		// printf("\n");
	}
	int sum = 0;
	for (int i = 0; i < SIZE; ++i)
		sum += array[i];
	printf("Sum = %d\n", sum);
	return 0;
}