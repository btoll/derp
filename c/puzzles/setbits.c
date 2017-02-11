#include <stdio.h>
#include <stdlib.h>

// Solution taken from http://clc-wiki.net/wiki/K%26R2_solutions:Chapter_2:Exercise_6
// and all credit goes to Pilcrow.
//
// Write a function setbits(x,p,n,y) that returns x with the n bits that begin at
// position p set to the rightmost n bits of y, leaving the other bits unchanged.

unsigned getbits(unsigned x, int offset, int n) {
    return (x >> (offset + 1 - n)) & ~(~0 << n);
}

void asbits(unsigned n) {
    int i;

    for (i = 4 * sizeof(n) - 1; i >= 0; i--) {
        getbits(n, i, 1) ? putchar('1') : putchar('0');

        if (i % 4 == 0)
            putchar(' ');
    }

    putchar('\n');
}

unsigned setbits(unsigned x, int p, int n, unsigned y) {
    /*
        Let's start with an `x` value of 11010101 and set the bits starting at offset 4 (zero-based) and replacing 3 bits:

            0. Compute a mask from the number of bits to replace -> 111
            1. Create a mask of one-bits whose length is `n`.
            2. Left shift the mask over the bits to be replaced and take the ones' complement of it:
                -> 111 << 4 + 1 - 3
                -> 111 << 2
                -> 11100
                -> ~11100
                -> 00011
            3. Bitwise AND'ing this will produce:
                   00011 <- computed mask
                11010101 <- x value
                --------
                11000001

                - Note this binary number has our target bits replaced with zeroes!
            4. Bitwise AND the `y` value and our msk:
                  111 <- original mask
                10111 <- y value
                -----
                10111
            5. Left shift by the offset:
                -> 10111 << 4 + 1 - 3
                -> 10111 << 2
                -> 1011100
            6. Finally, bitwise OR the values from #3 and #5
                 1011100
                11000001
                --------
                11011101

            P.S. Be amazed!!!

    */
	unsigned msk = ~(~0 << n);

	return (x & ~(msk << (p + 1 - n))) | ((y & msk) << (p + 1 - n));
}

int main(int argc, char **argv) {
    if (argc < 5) {
        printf("Usage: %s <x value> <offset> <bits to replace> <y value>\n", argv[0]);
        exit(1);
    }

    unsigned x = atoi(argv[1]);
    unsigned y = atoi(argv[4]);
    int offset = atoi(argv[2]);
    int n = atoi(argv[3]);

    printf("\n\n           offset: %d\n", offset);
    printf("  bits to replace: %d\n\n", n);

    printf("\t  x value: ");
    asbits(x);

    printf("\t  y value: ");
    asbits(y);

    printf("\tnew value: ");
    asbits(setbits(x, offset, n, y));

    printf("\n\n");

    return 0;
}

