#include <stdio.h>

void reverse(char s[]);

int main(void) {
    char s[] = "foobar";

    printf("%s\n", s);
    reverse(s);
    printf("%s\n", s);

    return 0;
}

void reverse(char s[]) {
    int i, j, tmp;

    for (j = 0; s[j] != '\0'; j++)
        ;

    for (i = 0, j--; i < j; i++, j--) {
        tmp = s[j];
        s[j] = s[i];
        s[i] = tmp;
    }
}

