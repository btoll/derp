#include <stdio.h>
#include <string.h>

void reverse(char *s, int p, int r) {
    if (p == r) {
        return;
    }

    int c = s[p];
    s[p] = s[r];
    s[r] = c;

    reverse(s, ++p, --r);
}

int main(void) {
    char s[] = "hello, world!";
    reverse(s, 0, strlen(s) - 1);
    printf("%s\n", s);

    return 0;
}

