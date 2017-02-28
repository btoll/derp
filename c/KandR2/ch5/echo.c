#include <stdio.h>

int main(int argc, char **argv) {
    while (*++argv)
        printf((--argc > 1) ? "%s " : "%s", *argv);

    printf("\n");

    return 0;
}

