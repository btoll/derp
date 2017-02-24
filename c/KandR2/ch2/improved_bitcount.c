#include <stdio.h>
#include <stdlib.h>

unsigned getbits(unsigned x, int offset, int n) {
    return x >> (offset + 1 - n) & ~(~0 << n);
}

void asbits(unsigned n, short b) {
    int i;

    for (i = b * sizeof(n) - 1; i >= 0; i--) {
        getbits(n, i, 1) ? putchar('1') : putchar('0');

        if (i % 4 == 0)
            putchar(' ');
    }

    putchar('\n');
}

// Solution taken from http://clc-wiki.net/wiki/K%26R2_solutions:Chapter_2:Exercise_9
// and all credit goes to Gregory Pietsch.

// In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit in x . Explain why.
// Use this observation to write a faster version of bitcount.

// /* bitcount:  count 1 bits in x */
// int bitcount(unsigned x)
// {
//     int b;
//
//     for (b = 0; x != 0; x >>= 1)
//         if (x & 01)
//             b++;
//     return b;
// }

// Answer:
//
// If x is odd, then (x-1) has the same bit representation as x except that the rightmost 1-bit is now a 0. In this case, (x & (x-1)) == (x-1).
//
// If x is even, then the representation of (x-1) has the rightmost zeros of x becoming ones and the rightmost one becoming a zero. Anding the two clears the rightmost 1-bit in x and all the rightmost 1-bits from (x-1).
//
// Here's the new version of bitcount:

// /* bitcount:  count 1 bits in x */
// int bitcount(unsigned x)
// {
//     int b;
//
//     for (b = 0; x != 0; x &= (x-1))
//         b++;
//     return b;
// }

//  Let's visualize this!

int bitcount(unsigned x) {
    int b;

    for (b = 0; x != 0; x &= (x - 1)) {
        asbits(x & (x - 1), 4);
        b++;
    }

    return b;
}

int main(int argc, char **argv) {
    printf("%d\n", bitcount(atoi(argv[1])));

    return 0;
}

