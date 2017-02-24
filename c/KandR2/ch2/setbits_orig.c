#include <stdio.h>
#include <stdlib.h>

// This MOSTLY works :) YMMV
unsigned gb(unsigned x, int offset, int n) {
    return (x >> offset + 1 - n) & ~(~0 << n);
}

unsigned asbits(unsigned n) {
    int i, k;

    for (i = 4 * sizeof(n) - 1; i >= 0; i--) {
        gb(n, i, 1) ? putchar('1') : putchar('0');

        if (i % 4 == 0)
            putchar(' ');
    }

    putchar('\n');
}

void addLowerOrderBits(unsigned *x, int n) {
    *x = *x | n;
}

unsigned getBits(unsigned x, int n) {
    return x & ~(~0 << n);
}

void rightPad(unsigned *x, int p) {
    // Replace (left shift) with zeroes.
    *x = *x << p;
}

void removeBits(unsigned *x, int p) {
    *x = *x >> p;
}

void setbits(unsigned *x, int p, int n, unsigned y) {
    unsigned yBits = getBits(y, n);
//     printf("yBits: %d\n", yBits);
    unsigned cached;

    if (p > 3) {
        cached = getBits(*x, p - n);
//         printf("cached %d\n", cached);
    }

    removeBits(x, p);

    printf("after removeBits %d\n", *x);
    asbits(*x);
    printf("\n");

    if (p > 3)
        rightPad(x, n);
    else
        rightPad(x, n);

    printf("after rightPad %d\n", *x);
    asbits(*x);
    printf("\n");

    addLowerOrderBits(x, yBits);

    printf("after addLowerOrderBits %d\n", *x);
    asbits(*x);
    printf("\n");

    if ((int) cached >= 0) {
        printf("now caching...\n");
        rightPad(x, p - n);
        printf("after rightPad %d\n", *x);
        asbits(*x);
        printf("\n");
        addLowerOrderBits(x, cached);
        printf("after addLowerOrderBits %d\n", *x);
        asbits(*x);
        printf("\n");
    }
}

int main(int argc, char **argv) {
    if (argc < 4) {
        printf("Usage: %s <hex or chars>\n", argv[0]);
        exit(1);
    }

    int x = atoi(argv[1]);
    int y = atoi(argv[4]);

    printf("%d -> ", x);
    asbits(x);
    setbits(&x, atoi(argv[2]), atoi(argv[3]), y);
    asbits(x);
    asbits(y);
//     asbits(*argv[4]);
    printf("result %d\n", x);
    return 0;
}

