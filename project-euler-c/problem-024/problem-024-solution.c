#include <stdio.h>

void swap(int *x, int *y) {
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

void print_array(int *array, int size) {
	for (int i = 0; i < size; ++i)
		printf("%d", array[i]);
	printf("\n");
}

int insertion_sort(int *array, int array_size) {
	for (int i = 1; i < array_size; ++i) {
		int j = i;
		while (j > 0 && array[j] < array[j - 1]) {
			swap(array + j, array + j - 1);
			--j;
		}
	}
	return 0;
}

int find_next_permutation(int *array, int size) {
	int left = size - 2;
	int right = size - 1;
	int last = size - 1;
	while (array[left] > array[left + 1])
		--left;
	while (array[right] < array[left])
		--right;
	swap(array + left, array + right);
	insertion_sort(array + left + 1, size - left);
	return 0;
}

int main(void) {
	int size = 10;
	int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	for (int i = 1; i < 1000000; ++i)
		find_next_permutation(array, size);
	print_array(array, size);
	return 0;
}