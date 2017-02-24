#include <stdio.h>

// Print input one word per line.
// http://clc-wiki.net/wiki/K%26R2_solutions:Chapter_1:Exercise_12
int main(void) {
    int c, inspace = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            if (inspace == 0) {
                inspace = 1;
                putchar('\n');
            }
        } else {
            inspace = 0;
            putchar(c);
        }
    }

    return 0;
}

