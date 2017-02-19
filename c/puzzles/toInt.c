#include <stdio.h>

int toInt(char *s) {
    int i, n, size;

    i = n = 0;

    for (size = 0; s[size] != '\0'; size++)
        ;

    while (i < size) {
        n = n * 10 + s[i] - '0';
        i++;
    }

    return n;
}

int main(int argc, char **argv) {
    int n = toInt("65");
    printf("%d %c\n", n, n);

    return 0;
}

