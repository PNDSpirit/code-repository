#include <stdio.h>
#define SIZE 2500
#define BASE 10

int max(int a, int b) {
	if (a > b)
		return a;
	else 
		return b;
}

// array size is presumably the size of the smaller array
int sum_array(int *array1, int *array2, int *array3, int array_size, int base) {
	for (int i = 0; i < array_size; ++i)
		array3[i] = array2[i] + array1[i];
	for (int i = array_size - 1; i > 0; --i) {
		array3[i - 1] += array3[i] / base;
		array3[i] -= (array3[i] / base) * base;
	}
	if (array3[0] > base - 1)
		return 1; // array too small
	else
		return 0;
}

int array_length(int *array, int array_length) {
	int i = 0;
	while (array[i] == 0)
		++i;
	return array_length - i;
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

int equal_array(int *array1, int *array2, int array_size) {
	for (int i = 0; i < array_size; ++i)
		array1[i] = array2[i];
	return 0;
}

int print_array(int *array, int array_size) {
	int i = 0;
	while (array[i] == 0)
		++i;
	for ( ; i < array_size; ++i)
		printf("%d", array[i]);
	return 0;
}

int main(void) {
	int array1[SIZE];
	int array2[SIZE];
	int array3[SIZE];
	for (int i = 0; i < SIZE; ++i) {
		array1[i] = 0;
		array2[i] = 0;
		array3[i] = 0;
	}
	array1[SIZE - 1] = 1;
	array2[SIZE - 1] = 1;
	int index = 2;
	while (array_length(array3, SIZE) < 1000) {
		++index;
		sum_array(array1, array2, array3, SIZE, BASE);
		if (index % 2 == 0)
			equal_array(array1, array3, SIZE);
		else
			equal_array(array2, array3, SIZE);
	}
	printf("Index: %d\n", index);
	return 0;
}