#include <stdio.h>

int main(int argc, char **argv) {
    int c = *argv[1];
    int isUpper = c >= 'A' && c <= 'Z';

    if (isUpper)
        printf("lowering the case of %c => %c\n", c, c + 'a' - 'A');
    else
        printf("returning unchanged %c\n", c);

    return 0;
}

