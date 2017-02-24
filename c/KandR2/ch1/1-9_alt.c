#include <stdio.h>

int main(void) {
    int c, i;;

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            putchar(c);

            // A nop if a space continues to be entered.
            while ((c = getchar()) == ' ' && c != EOF)
                ;
        }

        if (c == EOF) {
            break;
        }

        putchar(c);
    }

    return 0;
}

