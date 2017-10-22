#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

int min (int first, int second) {
	if (first < second)
		return first;
	return second;
}

int main(int argc, char const *argv[]) {
	FILE *file;
	file = fopen("p081_matrix.txt", "r");
	int matrix[81][81];
	char number[5];
	// add a border to prevent overflows :(
	for (int i = 0; i < 81; ++i) {
		for (int j = 0; j < 81; ++j) {
			matrix[i][j] = INT_MAX;
		}
	}

	// get input into the matrix
	for (int i = 0; i < 80; ++i) {
		for (int j = 0; j < 80; ++j) {
			int k = 0;
			while (1) {
				number[k] = fgetc(file);
				if (number[k] == ',' || number[k] == '\n')
					break;
				++k;
			}
			number[k] = 0;
			matrix[i][j] = atoi(number);
		}
	}
	
	// calculate it
	for (int object = 157; object >= 0; --object) {
		for (int i = 0; i < 80; ++i) {
			for (int j = 0; j < 80; ++j) {
				if (i + j == object) {
					matrix[i][j] += min(matrix[i + 1][j], matrix[i][j + 1]);
				}
			}
		}
	}
	printf("Answer: %d\n", matrix[0][0]);
	return 0;
}