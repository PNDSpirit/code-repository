#include <stdio.h>
#include <gmp.h>
#define BASE 10

void reverse(const mpz_t number, mpz_t result) {
	mpz_t new;
	mpz_t remainder;
	mpz_t number_copy;
	mpz_init(remainder);
	mpz_init(new);
	mpz_init(number_copy);
	mpz_set(number_copy, number);
	while (mpz_cmp_ui(number_copy, 0)) {
		// new *= BASE;
		mpz_mul_si(new, new, BASE);
		// new += number % BASE;
		mpz_mod_ui(remainder, number_copy, BASE);
		mpz_add(new, new, remainder);
		// number /= BASE;
		mpz_fdiv_q_ui(number_copy, number_copy, BASE);
	}
	mpz_set(result, new);
	mpz_clear(remainder);
	mpz_clear(new);
}

int is_palindrome(mpz_t number) {
	mpz_t reversed;
	mpz_init(reversed);
	reverse(number, reversed);
	// equality function
	if (!(mpz_cmp(number, reversed)))
		return 1;
	return 0;
}

int is_lychrel(unsigned long input) {
	mpz_t number, number_reveresed;
	mpz_init(number);
	mpz_init(number_reveresed);
	mpz_add_ui(number, number, input);
	for (int i = 0; i < 50; ++i) {
		// number += reverse(number);
		reverse(number, number_reveresed);
		mpz_add(number, number, number_reveresed);
		if (is_palindrome(number)) {
			return 0;
		}
	}
	return 1;
}

int main(void) {
	int count = 0;
	for (long i = 0; i < 10000; ++i) {
		if (is_lychrel(i))
			++count;
	}
	printf("Answer: %d\n", count);
	return 0;
}