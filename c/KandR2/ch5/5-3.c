#include <stdio.h>

// Writer a pointer version of strcat.

void _strcat(char *s, char *t) {
    while (*s++)
        ;

    --s;

    while (*s++ = *t++)
        ;
}

int main(int argc, char **argv) {
    char s[1000] = "yo";
    char t[] = "be";

    _strcat(s, t);
    printf("%s\n", s);

    return 0;
}

