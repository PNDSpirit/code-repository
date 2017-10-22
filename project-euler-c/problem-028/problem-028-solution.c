#include <stdio.h>

int main(int argc, char *argv[]) {
    long total = 1;
    int number = 1;
    int growth = 1;
    for (int i = 0; i < 500; ++i) {
        for (int j = 0; j < 4; ++j) {
            number += growth;
            total += number;
        }       
        growth += 2;
    }       
    printf("Answer: %li\n", total);
}
