#include <stdio.h>

// Write an alternate version of squeeze(s1,s2) that deletes each character in the string
// s1 that matches any character in the string s2 .
void squeeze2(char *s1, char *s2) {
    int i, j, k;

    for (k = 0; s2[k] != '\0'; k++) {
        for (i = j = 0; s1[i] != '\0'; i++)
            if (s1[i] != s2[k])
                s1[j++] = s1[i];

        s1[j] = '\0';
    }
}

int main(int argc, char **argv) {
    squeeze2(argv[1], argv[2]);
    printf("%s\n", argv[1]);

    return 0;
}

