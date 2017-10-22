#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
	if (argc != 3) {
		printf("Usage: %s width height", argv[0]);
		return 1;
	}
	int width = atoi(argv[1]) + 1;
	int height = atoi(argv[2]) + 1;
	long long matrix[width][height];
	// set default values
	for (int i = 0; i < width; ++i)
		matrix[i][0] = 1;
	for (int i = 0; i < height; ++i)
		matrix[0][i] = 1;
	for (int i = 1; i < width; ++i) {
		for (int j = i; j < width; ++j)
			matrix[j][i] = matrix[j - 1][i] + matrix[j][i - 1];
		for (int j = i; j < height; ++j)
			matrix[i][j] = matrix[i - 1][j] + matrix[i][j - 1];
	}
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			printf("%ld  ", matrix[j][i]);
		}
		printf("\n");
	}
	printf("result = %ld\n", matrix[width - 1][height - 1]);
	return 0;
}