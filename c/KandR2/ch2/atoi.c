#include <stdio.h>

// A naive implementation.
//
//      ./a.out 123 => 123
//      ./a.out 456 => 456
//      ...
//

int main(int argc, char **argv) {
    char *str = argv[1];
    int n = 0, i;

    for (i = 0; str[i] >= '0' && str[i] <= '9'; i++)
        n = n * 10 + str[i] - '0';

    printf("%d\n", n);

    return 0;
}

