#include <stdio.h>

int reverse(char *s) {
}

int strindex(char *s, char *t) {
    int i, j, k;

    for (i = 0; s[i] != '\0'; i++) {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;

        if (k > 0 && t[k] == '\0')
            return i;
    }

    return -1;
}

int main(int argc, char **argv) {
    printf("%d\n", strindex("I would if a could, you bet!", "ould"));

    return 0;
}

