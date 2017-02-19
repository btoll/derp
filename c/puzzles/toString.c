#include <stdio.h>

void reverse(char *s) {
    int c, i, j;

    for (j = 0; s[j] != '\0'; j++)
        ;

    for (i = 0, j--; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

int *toString(int n, char *buf) {
    int k = 0;

    do {
        buf[k++] = (n % 10) + '0';
    } while (n /= 10);

    buf[k] = '\0';
    reverse(buf);
}

int main(int argc, char **argv) {
    char buf[255];
    toString(732, buf);
    printf("%s\n", buf);

    return 0;
}

