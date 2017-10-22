#include <stdio.h>
#include <stdlib.h>

int *max_val(int *a, int *b) {
	if (*a > *b)
		return a;
	return b;
}

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int max_heapify(int *heap, int heap_size, int index) {
	/* cover cases if 0 or 1 children exist */
	if (index * 2 + 2 >= heap_size) {	/* check if the right child doesn't exists */
		if (index * 2 + 1 >= heap_size) {	/* check if the left child doesn't exists */
			return 1;
		}
		/* only the left child exists - swap if needed */
		if (heap[index] < heap[index * 2 + 1]) {
			swap(heap + index, heap + index * 2 + 1);
			return 2;
		}
		return 0;
	}
	/* swap with the bigger child and heapify the child */
	int *max = max_val(heap + index * 2 + 1, heap + index * 2 + 2);
	if (heap[index] < *max) {
		swap(heap + index, max);
		max_heapify(heap, heap_size, max - heap);
	}
	return 0;
}

int build_max_heap(int *heap, int heap_size) {
	for (int i = heap_size / 2 - 1; i >= 0; --i) {
		max_heapify(heap, heap_size, i);
	}
	return 0;
}

int extract_root(int *heap, int size) {
	swap(heap + size - 1, heap);
	max_heapify(heap, size - 1, 0);
	return 0;
}

int build_sorted_array(int *heap, int size) {
	for (; size > 0; --size) {
		extract_root(heap, size);
	}
	return 0;
}

int heap_sort(int *array, int size) {
	build_max_heap(array, size);
	build_sorted_array(array, size);
	// for (int i = 0; i < size / 2; ++i)
	// 	swap(array + i, array + size - 1 - i);
	return 0;
}

int main(void) {
	int heap[] = {1, 2, 3, 4, 1, 3, 6, 2, 12, 53, 1, 2, 4, 12, 42, 65};
	int heap_size = sizeof(heap) / sizeof(int);
	heap_sort(heap, heap_size);
	for (int i = 0; i < heap_size; ++i)
		printf("%d ", heap[i]);
	printf("\n");
	return 0;
}
