#include <stdio.h>
#include <stdlib.h>

// Returns the (right-adjusted) n-bit field of `x` that begins at position `p`.
unsigned getbits(unsigned x, int p, int n) {
    return (x >> (p + 1 - n)) & ~(~0 << n);
}

int main(int argc, char **argv) {
    if (argc < 4) {
        printf("Usage: %s <x> <p> <n>\n", argv[0]);
        exit(1);
    }

    printf("%d\n", getbits(atoi(argv[1]), atoi(argv[2]), atoi(argv[3])));

    return 0;
}

