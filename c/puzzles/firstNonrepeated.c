#include <stdio.h>
#include <string.h>

int firstNonrepeated(char *s) {
    int chars[128];
    int i, len;

    for (i = 0; i < 128; i++)
        chars[i] = 0;

    for (i = 0, len = strlen(s); i < len; i++) {
        if (!chars[s[i]])
            chars[s[i]] = 1;
        else
            chars[s[i]] = chars[s[i]] + 1;
    }

    for (i = 0; i < len; i++)
        if (chars[s[i]] == 1)
            return s[i];

    return -1;
}

int main(void) {
    char *s = "hello, world!";
    printf("%c\n", firstNonrepeated(s));
    return 0;
}

