/* Format (to fit 812 in an array with size 10)
** it would be: [0][0][0][0][0][0][0][8][1][2]
*/ 
#include <stdio.h>
#define SIZE 250
#define BASE 10

int max(int a, int b) {
	if (a > b)
		return a;
	else 
		return b;
}

// array size is presumably the size of the smaller array
int sum_array(int *array1, int *array2, int array_size, int base) {
	for (int i = 0; i < array_size; ++i)
		array1[i] += array2[i];
	for (int i = array_size - 1; i > 0; --i) {
		array1[i - 1] += array1[i] / base;
		array1[i] -= (array1[i] / base) * base;
	}
	if (array1[0] > base - 1)
		return 1; // array too small
	else
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
	for (int i = 1; i <= 100; ++i)
		multiply_array(array, SIZE, i, BASE);
	int sum = 0;
	for (int i = 0; i < SIZE; ++i)
		sum += array[i];
	printf("Sum = %d\n", sum);
	return 0;
}