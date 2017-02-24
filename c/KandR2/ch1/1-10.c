#include <stdio.h>

int main(void) {
    int c, i = 0;

    while ((c = getchar()) != EOF) {
        i = 0;

        if (c == '\\') {
            putchar('\\');
            putchar('\\');
            i = 1;
        }

        if (c == '\t') {
            putchar('\\');
            putchar('t');
            i = 1;
        }

        if (c == '\b') {
            putchar('\\');
            putchar('b');
            i = 1;
        }

        if (i == 0) {
            putchar(c);
        }
    }

    return 0;
}

