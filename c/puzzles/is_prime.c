#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// gcc -Wall prime.c -lm

int main(int argc, char **argv) {
    if (argc == 1) {
        printf("Usage: %s number\n", argv[0]);
        exit(1);
    }

    short int n = atoi(argv[1]);

    if (n < 2 || n % 2 == 0) {
        printf("%d is not prime\n", n);
        exit(2);
    }

    short int i = 3;
    int p = (int) sqrt(n);

    for (; i <= p; ++i) {
        if (n % i == 0) {
            printf("%d is not prime\n", n);
            exit(0);
        }
    }

    printf("%d is prime\n", n);
    return 0;
}

