#include <stdio.h>
#include <stdlib.h>

int max(int first, int second) {
	if (first > second)
		return first;
	return second;
}

int main(int argc, char const *argv[]) {
	FILE *file;
	file = fopen("p018_triangle.txt", "r");
	int number_matrix[15][15];
	for (int i = 0; i < 15; ++i) {
		for (int j = 0; j < 15; ++j) {
			number_matrix[i][j] = 0;
		}
	}
	char number[2];
	for (int i = 0; i < 15; ++i) {
		for (int j = 0; j <= i; ++j) {
			number[0] = fgetc(file);
			number[1] = fgetc(file);
			number_matrix[i][j] = atoi(number);
			fgetc(file); // space or newline
		}
	}
	// bottom to top line
	for (int i = 13; i >= 0; --i) {
		for (int j = 0; j <= i; ++j) {
			number_matrix[i][j] += max(number_matrix[i + 1][j], number_matrix[i + 1][j + 1]);
		}
	}
	printf("Answer: %d\n", number_matrix[0][0]);
	return 0;
}