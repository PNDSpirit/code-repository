#include <stdio.h>

int main(void) {
	char *fizzbuzz[] = {"%d\n", "fizz\n", "buzz\n", "fizzbuzz\n"};
	for (int i = 1; i <= 100; ++i)
		printf((!(i%3) + !(i%5) * 2)[fizzbuzz], i);
	return 0;
}