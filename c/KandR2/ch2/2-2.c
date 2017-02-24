#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

// Write a loop equivalent to the for loop without using the logical operators && or ||.
int _getline(char line[], int maxline);

int main(void) {
    int len;
    char line[MAXLINE];

    while ((len = _getline(line, MAXLINE)) > 0)
        printf("%s", line);

    return 0;
}

int _getline(char s[], int lim) {
    int c, i;

    for (i = 0;
        (
            (i < lim - 1) +
            ((c = getchar()) != EOF) +
            (c != '\n')
        ) == 3
    ; ++i)
        s[i] = c;

    if (c == '\n') {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';

    return i;
}

