#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define MAX_WORD_LENGTH 25

int is_triangular(int number) {
	int i;
	for (i = 0; (i * (i + 1)) / 2 <= number; ++i) {
		if ((i * (i + 1)) / 2 == number) {
			return i; // it is
		}
	}
	return 0; // it is not
}


int main(int argc, char const *argv[]) {
	FILE *file;
	file = fopen("p042_words.txt", "r");
	char input_char;
	char input_word[MAX_WORD_LENGTH];
	int triangular_numbers_count = 0;
	while ((input_char = fgetc(file)) != EOF) {
		// skip syntax
		while (input_char == '\"' || input_char == ',') {
			input_char = getc(file);
		}
		// get the word
		int i = 0;
		int word_sum = 0;
		while (!(input_char == '\"' || input_char == ',')) {
			word_sum += input_char - 64;
			input_word[i++] = input_char;
			input_char = fgetc(file);
		}
		if (is_triangular(word_sum))
			++triangular_numbers_count;
		input_word[i] = '\0';
	}
	printf("Answer: %d\n", triangular_numbers_count);
	return 0;
}