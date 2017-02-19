#include <stdio.h>

int primes[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };
unsigned int size = sizeof(primes) / sizeof(*primes);

int binarySearch(int *array, int target, int min, int max) {
    int guess;

    while (1) {
        if (min > max)
            return -1;

        guess = (min + max) / 2;

        if (array[guess] == target)
            return guess;
        else if (array[guess] < target)
            min = guess + 1;
        else if (array[guess] > target)
            max = guess - 1;
    }
}

int main(int argc, char **argv) {
    printf("%d\n", binarySearch(primes, 97, 0, size));
    return 0;
}

