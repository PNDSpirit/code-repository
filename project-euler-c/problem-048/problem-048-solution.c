#include <stdio.h>
#define SIZE 13
#define BASE 10

int max(int a, int b) {
	if (a > b)
		return a;
	else 
		return b;
}

// array size is presumably the size of the smaller array
// array1 += array2;
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

void print_array(int *array, int size) {
	int i = 0;
	while (array[i] == 0) {
		if (i > size)
			break;
		++i;
	}
	if (i >= size) // ?
		printf("0");
	for ( ; i < size; ++i)
		printf("%d", array[i]);
}

int null_array(int *array, int size) {
	for (int i = 0; i < size; ++i) 
		array[i] = 0;
	return 0;
}


int main(void) {
	int sum[SIZE];
	int number[SIZE];
	null_array(sum, SIZE);
	null_array(number, SIZE);
	for (int i = 1; i <= 1000; ++i) {
		null_array(number, SIZE);
		number[SIZE - 1] = 1;
		for (int j = 0; j < i; ++j) {
			multiply_array(number, SIZE, i, 10);
		}
		sum_array(sum, number, SIZE, 10);
	}
	// print last 10 digits;
	printf("Result: ");
	for (int i = SIZE - 10; i < SIZE; ++i)
		printf("%d", sum[i]);
	printf("\n");
	return 0;
}