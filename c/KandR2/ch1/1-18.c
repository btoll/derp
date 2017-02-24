#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int _getline(char line[], int maxline);
void copy(char to[], char from[]);

int main(void) {
    int len;
    int slen;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;

    while ((len = _getline(line, MAXLINE)) > 0)
        if (len > max) {
            max = len;
            copy(longest, line);

            printf("\n%d\n", strlen(longest));
        }

    if (max > 0)
        printf("%s", longest);

    return 0;
}

int _getline(char s[], int lim) {
    int c, i;
    int blank = 1;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
        blank = 0;
    }


    if (!blank) {
        while (s[i - 1] == '\t' || s[i - 1] == ' ') {
            s[i] = '\0';
            --i;
        }
    }

    if (c == '\n') {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';

    return i;
}

void copy(char to[], char from[]) {
    int i = 0;

    while ((to[i] = from[i]) != '\0')
        ++i;
}

