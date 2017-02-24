#include <stdio.h>

#define swap(x, y) \
    x ^= y; \
    y ^= x; \
    x ^= y;

int main(void) {
    int x = 5;
    int y = 3;

    printf("%d %d\n", x, y);
    swap(x, y);
    printf("%d %d\n", x, y);

    return 0;
}

