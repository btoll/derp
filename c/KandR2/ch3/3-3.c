#include <stdio.h>
#include <string.h>

// Naive implementation of http://clc-wiki.net/wiki/K%26R2_solutions:Chapter_3:Exercise_3
//
// Write a function expand(s1,s2) that expands shorthand notations like a-z in the string s1
// into the equivalent complete list abc...xyz in s2 . Allow for letters of either case and
// digits, and be prepared to handle cases like a-b-c and a-z0-9 and -a-z . Arrange that a
// leading or trailing - is taken literally.

#define UPPER(N) ((N) >= 'A' && (N) <= 'Z')
#define LOWER(N) ((N) >= 'a' && (N) <= 'z')
#define DIGIT(N) ((N) >= '0' && (N) <= '9')
#define AN(N) (UPPER(N) || LOWER(N) || DIGIT(N))

int copy(char *s2, int curPos, int end, int i) {
    for (; curPos <= end; curPos++)
        s2[i++] = curPos;

    return i;
}

void expand(char *s1, char *s2) {
    int i = 0;

    if (strlen(s1) > 3) {
        int m = 0;

        while (s1[m]) {
            if (AN(s1[m]) && AN(s1[m + 2]))
                i = copy(s2, s1[m], s1[m + 2], i);

            m += 3;
        }
    } else {
        if (AN(s1[0]) && AN(s1[2]))
            i = copy(s2, s1[0], s1[2], i);
    }

    s2[i] = '\0';
}

int main(int argc, char **argv) {
    char *range[] = { "a-z", "A-Z", "a-z0-9A-Z", "1-5a-e", "0-9", NULL };
    char *buff;
    int i;

    for (i = 0; range[i]; i++)
        expand(range[i], buff), printf("%s\n", buff);

    return 0;
}

