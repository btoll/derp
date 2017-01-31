#include <stdio.h>

// Note that this version doesn't use any string manipulation functions since I did this when working
// my way through K&R2 and chapter 1 hadn't introduced any of these functions yet.

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

