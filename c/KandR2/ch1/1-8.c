#include <stdio.h>

int main(void) {
    int c, i = 0;

    while ((c = getchar()) != EOF) {
        putchar(c);

        if (c == ' ' || c == '\t' || c == '\n') {
            i++;
        }
    }

    printf("%d", i);

    return 0;
}

