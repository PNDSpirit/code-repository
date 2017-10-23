#include <stdio.h>
#include <stdlib.h>
#define OUTER_BORDER 47
#define WHITESPACE 43
#define POLE 41
#define RING 44

int tower_of_hanoi_rings;
int tower_of_hanoi_poles;
int matrix_width;
int matrix_height;

int abs(int value) {
	if (value < 0)
		return -value;
	return value;
}

int should_print_ring(int array_value, int j) {
	int pole = tower_of_hanoi_rings;
	j %= tower_of_hanoi_rings * 2 + 1;
	// to the left of the pole
	if (abs(pole - j) <= array_value)
		return 1;
	return 0;
}

void print_matrix(int (* matrix)[tower_of_hanoi_rings]) {
	// print top border
	for (int i = 0; i < matrix_width + 2; ++i)
		printf("\033[8;%dm  \033[0m", OUTER_BORDER);
	// print inner top border
	printf("\n");
	printf("\033[8;%dm  \033[0m", OUTER_BORDER);
	for (int i = 0; i < matrix_width; ++i)
		printf("\033[8;%dm  \033[0m", WHITESPACE);
	printf("\033[8;%dm  \033[0m", OUTER_BORDER);
	printf("\n");

	// towers
	for (int i = 0; i < matrix_height - 2; ++i) {
		// left border characters
		printf("\033[8;%dm  \033[0m", OUTER_BORDER);
		printf("\033[8;%dm  \033[0m", WHITESPACE);

		// THE COMPLICATED SHIT
		for (int j = 0; j < matrix_width - 2; ++j) {
			if (((j - tower_of_hanoi_rings) % (tower_of_hanoi_rings * 2 + 1) == 0) && i >= 0)
				printf("\033[8;%dm  \033[0m", POLE);
			else if (should_print_ring(matrix[j / (2 * tower_of_hanoi_rings + 1)][i], j))
				printf("\033[8;%dm  \033[0m", RING);
			else
				printf("\033[8;%dm  \033[0m", WHITESPACE);
		}

		// right border characters and newline
		printf("\033[8;%dm  \033[0m", WHITESPACE);
		printf("\033[8;%dm  \033[0m\n", OUTER_BORDER);
	}

	// print bottom border
	for (int i = 0; i < matrix_width + 2; ++i)
		printf("\033[8;%dm  \033[0m", OUTER_BORDER);
	printf("\n");

}

int print_two_dimensional_array(int (* matrix)[tower_of_hanoi_rings]) {
	for (int i = 0; i < tower_of_hanoi_poles; ++i) {
		for (int j = 0; j < tower_of_hanoi_rings; ++j) {
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
	return 0;
}

int game_is_over(int (* matrix)[tower_of_hanoi_rings]) {
	int any_pole_is_solved = 0;
	for (int i = 1; i < tower_of_hanoi_poles; ++i) {
		int current_pole_is_solved = 1; // is solved
		for (int j = 0; j < tower_of_hanoi_rings; ++j) {
			if (matrix[i][j] != j + 1)
				current_pole_is_solved = 0;
		}
		if (current_pole_is_solved)
			any_pole_is_solved = 1;
	}
	return any_pole_is_solved;
}

int move_ring(int (* matrix)[tower_of_hanoi_rings], int from, int to) {
	// find the first ring on the 'from' pole
	int from_ring_index = 0;
	int ring_value_to_move;
	while (matrix[from][from_ring_index] == 0 && from_ring_index < tower_of_hanoi_rings)
		++from_ring_index;
	// if there is no ring - pole is empty - error
	if (matrix[from][from_ring_index] == 0)
		return 1; // pole is empty
	// get a copy of the ring and set it to 0 on the pole
	ring_value_to_move = matrix[from][from_ring_index];
	matrix[from][from_ring_index] = 0;
	// find the first ring on the 'to' pole
	int to_ring_index = 0;
	while (matrix[to][to_ring_index] == 0 && to_ring_index < tower_of_hanoi_rings)
		++to_ring_index;
	matrix[to][to_ring_index - 1] = ring_value_to_move;
	return 0; // success
}

/* TODO: add support for customizable number of poles */
int main(int argc, char const *argv[]) {
	if (argc != 3) {
		printf("Usage: ~$ %s [number of rings] [number of poles]\n", argv[0]);
		return 1;
	}
	// set values
	tower_of_hanoi_rings = atoi(argv[1]);
	tower_of_hanoi_poles = atoi(argv[2]);
	matrix_width = tower_of_hanoi_poles + 2 + tower_of_hanoi_rings * tower_of_hanoi_poles * 2;
	matrix_height = tower_of_hanoi_rings + 2;
	// check if values are in range
	if (tower_of_hanoi_rings < 2 || tower_of_hanoi_poles < 3) {
		printf("Bad arguments.\n");
		return 2;
	}
	// declare array
	int matrix[tower_of_hanoi_poles][tower_of_hanoi_rings];
	printf("declaring: %p\n", matrix);
	// set default rings
	for (int i = 0; i < tower_of_hanoi_poles; ++i)
		for (int j = 0; j < tower_of_hanoi_rings; ++j)
			matrix[i][j] = 0;
	for (int i = 0; i < tower_of_hanoi_rings; ++i)
		matrix[0][i] = i + 1;

	// game
	int from_input, to_input;
	print_matrix(matrix);
	int moves = 0;
	while (!game_is_over(matrix)) {
		// get input
		printf("Enter a command: ");
		scanf("%d %d", &from_input, &to_input);
		// fflush(NULL);
		// error check the input
		while (!(from_input <= tower_of_hanoi_poles && from_input > 0 && to_input <= tower_of_hanoi_poles && to_input > 0 && from_input != to_input)) {
			print_matrix(matrix);
			printf("Input error! The format is [pole_you_take_from_number] [recipient_pole_number]. Enter a new command.\n");
			scanf("%d %d", &from_input, &to_input);
		}
		// move the ring and check if possible
		while (move_ring(matrix, from_input - 1, to_input - 1) == 1) {
			print_matrix(matrix);
			printf("Input error! The format is [pole_you_take_from_number] [recipient_pole_number]. Enter a new command.\n");
			scanf("%d %d", &from_input, &to_input);
		}
		// print
		printf("\n\n\n");
		print_matrix(matrix);
		++moves;
	}
	printf("You won in %d moves!\n", moves);
	return 0;

}

/*
a = 8; b = 41 red
a = 8; b = 42 green
a = 8; b = 43 yellow
a = 8; b = 44 blue = ring
a = 8; b = 45 purple = pole
a = 8; b = 46 cyan = whitespace
a = 8; b = 47 white = outer border
*/