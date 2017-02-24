#include <stdio.h>

int main(void) {
    int c, pc, i = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            if (pc != ' ') {
                putchar(c);
            }
        }

        // We haven't met `else` yet!
        if (c != ' ') {
            putchar(c);
        }

        pc = c;
    }

    return 0;
}

