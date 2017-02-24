#include <stdio.h>

int power(int m, int n);

int main(void) {
    int i;

    for (i = 1; i <= 10; i++)
        printf("%d %d %d\n", i, power(2, i), power(3, i));
}

int power(int base, int n) {
    int i, res = 1;

    for (i = 1; i <= n; i++)
        res = res * base;

    return res;
}

