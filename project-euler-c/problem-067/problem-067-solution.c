#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

int max(int first, int second) {
	if (first > second)
		return first;
	return second;
}

int main(int argc, char const *argv[]) {
	FILE *file;
	file = fopen("p067_triangle.txt", "r");
	int number_matrix[SIZE][SIZE];
	char number[2];
	// input
	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j <= i; ++j) {
			number[0] = fgetc(file);
			number[1] = fgetc(file);
			number_matrix[i][j] = atoi(number);
			fgetc(file); // skip space or newline
		}
	}
	// sum
	for (int i = SIZE - 2; i >= 0; --i) {
		for (int j = 0; j <= i; ++j) {
			number_matrix[i][j] += max(number_matrix[i + 1][j], number_matrix[i + 1][j + 1]);
		}
	}
	printf("Answer: %d\n", number_matrix[0][0]);
	return 0;
}