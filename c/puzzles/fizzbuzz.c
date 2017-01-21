#include <stdio.h>

void main(void) {
    unsigned int short i, fizz, buzz;

    for (i = 0x1; i <= 0x64; i++) {
        fizz = buzz = 0x0;

        if (i % 0x3 == 0x0) {
            fizz = 0x3;
            printf("fizz, number %d\n", i);
        }

        if (i % 0x5 == 0x0) {
            buzz = 0x5;
            printf("buzz, number %d\n", i);
        }

        // if (i % 0xf == 0x0) {
        if ((fizz & buzz) == 0x1) {
            printf("fizzbuzz, number %d\n", i);
        }
    }
}

