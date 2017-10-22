#include <stdio.h>
#include <stdlib.h>

void xor_crypt(char *array, int array_size, char *key, int key_size) {
	for (int i = 0; i < array_size; ++i) {
		array[i] = array[i] ^ key[i % key_size];
	}
}

int main(void) {
	FILE *fp;
	fp = fopen("p059_cipher.txt", "r");
	char number[2] = {0, 0};
	char numbers[1201];
	int numbers_count;
	while (1) {
		char input = fgetc(fp);
		if (input == EOF) {
			break;
		}
		else if (input >= 48 && input <= 57) {
			if (number[0] != 0) {
				number[1] = input;
			}
			else {
				number[0] = input;
			}
		}
		else if (input == 44) {
			numbers[numbers_count++] = atoi(number);
			number[0] = 0;
			number[1] = 0;
		}
	}
	char key[3] = "god";
	xor_crypt(numbers, 1201, key, 3);
	int sum = 0;
	for (int i = 0; i < 1201; ++i) {
		printf("%c", numbers[i]);
		sum += numbers[i];
	}
	printf("\nSum = %d\n", sum);
	return 0;
}
