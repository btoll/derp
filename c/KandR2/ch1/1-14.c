#include <stdio.h>

int main(void) {
    int chars[78];
    int c, i;

    for (i = 0; i < 78; i++)
        chars[i] = 0;

    while ((c = getchar()) != EOF) {
        if ('0' <= c && c <= '~') {
            ++chars[c-'0'];
        }
    }

    printf("Chars distribution:\n");

    for (i = 0; i < 78; i++)
        printf("%c = %d\n", i+'0', chars[i]);

    return 0;
}

