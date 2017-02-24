#include <stdio.h>

int main(void) {
    int c, i;
    int ndigit[10];
    int nwhite, nother;

    nwhite = nother = 0;

    for (i = 0 ; i < 10; i++)
        ndigit[i] = 0;

    while ((c = getchar()) != EOF)
        if ('0' <= c && c <= '9')
            ++ndigit[c-'0'];
        else if (c == ' ' || c == '\t' || c == '\n')
            ++nwhite;
        else
            ++nother;

    printf("\ndigits =");
    for (i = 0; i < 10; i++)
        printf(" %d", ndigit[i]);
    printf(", white space = %d, other = %d\n",
            nwhite, nother);

    return 0;
}

