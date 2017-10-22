#include <stdio.h>
#include <stdlib.h>

void insertion_sort_swap(int *x, int *y) {
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

int insertion_sort(int *array, int array_size) {
	for (int i = 1; i < array_size; ++i) {
		int j = i;
		while (j > 0 && array[j] < array[j - 1]) {
			insertion_sort_swap(array + j, array + j - 1);
			--j;
		}
	}
}

int main(void) {
	// declare stuff
	int array[] = {9, -1, 2, 2, 1, 4, 5, 1, 2, 76, 7, 8, 3, 23, 53, 12};
	int length = sizeof(array) / sizeof(array[0]);
	int sorted_array[length];
	printf("Length: %d\n", length);
	// sort the array
	insertion_sort(array, length);
	// print out the array
	for (int i = 0; i < length; ++i)
		printf("%d, ", array[i]);
	printf("\n");
}