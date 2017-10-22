#include <stdio.h>

int main(void) {
	int counter = 0;
	for (int h = 0; h <= 1; ++h) {
		for (int g = 0; g <= 2; ++g) {
			for (int f = 0; f <= 4; ++f) {
				for (int e = 0; e <= 10; ++e){
					for (int d = 0; d <= 20; ++d) {
						for (int c = 0; c <= 40; ++c) {
							for (int b = 0; b <= 100; ++b) {
								for (int a = 0; a <= 200; ++a) {
									int sum = a * 1 + b * 2 + c * 5 + d * 10 + e * 20 + f * 50 + g * 100 + h * 200;
									if (sum > 200)
										break;
									if (sum == 200) {
										counter++;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	printf("Answer: %d\n", counter);
	return 0;
}