#include <stdio.h>

// Write the function strend(s,t) , which returns 1 if the string t occurs at the end of the string s , and zero otherwise.

int _strlen(char *s) {
    int n = 0;

    while (*s++)
        ++n;

    return n;
}

int strend(char *s, char *t) {
    int slen = _strlen(s);
    int tlen = _strlen(t);

    if (tlen > slen)
        return 0;

    s += slen - tlen;           // Increments to the point of comparison.

    while (*s++ == *t++)        // Tests for equality.
        if (*s == '\0')         // Checks for null character while lines are equal.
            return 1;

    return 0;
}

int main(void) {
    char *s = "The world is a vampire";
    char *t = "vampire";

    printf("%d\n", strend(s, t));

    return 0;
}

