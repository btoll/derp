#include <stdio.h>
#include <string.h>

// Remove all the vowels from the sentence "Bttl f th Vwls: Hw vs. Grzny".
// All chars are assumed to be ascii encoded.

void *removeChars(char *s, char *toRemove, char *buf) {
    int ascii[128];
    int i, j, len;

    for (i = 0; i < 128; i++)
        ascii[i] = 0;

    for (i = 0; toRemove[i] != '\0'; i++)
        ascii[toRemove[i]] = 1;

    for (i = 0, j = 0, len = strlen(s); i < len; i++)
        if (ascii[s[i]] != 1)
            buf[j++] = s[i];

    buf[j] = '\0';
}

int main(void) {
    char *s = "Battle of the Vowels: Hawaii vs. Grozny";
    char buf[strlen(s)];

    removeChars(s, "aeiou", buf);
    printf("%s\n", buf);
    return 0;
}

