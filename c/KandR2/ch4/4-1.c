#include <stdio.h>

// Return the position of the rightmost occurrence of `t` in `s`, or -1 if not found.

int strindex(char *s, char *t) {
    int i, j, k;
    int found = -1;

    for (i = 0; s[i] != '\0'; i++) {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;

        if (k > 0 && t[k] == '\0')
            found = i;
    }

    return found;
}

int main(int argc, char **argv) {
    printf("%d\n", strindex("I would if a could, you bet!", "ould"));

    return 0;
}

