#include <stdio.h>

int primes[25] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };
unsigned int len = sizeof(primes) / sizeof(len);

int binary_search(int min, int max, int target) {
    if (min > max) {
        return -1;
    }

    int guess = (max + min) / 2;

    if (primes[guess] == target) {
        return target;
    }

    if (primes[guess] < target) {
        return binary_search(guess + 1, max, target);
    } else {
        return binary_search(min, guess - 1, target);
    }
}

void main(void) {
    printf("%d", binary_search(0, len - 1, 97));
}

