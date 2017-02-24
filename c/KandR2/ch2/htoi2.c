#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HEX_UPPER(N) ((N) >= 'A' && (N) <= 'F')
#define HEX_LOWER(N) ((N) >= 'a' && (N) <= 'f')
#define HEX_DIGIT(N) ((N) >= '0' && (N) <= '9')
// #define IS_HEX(N) (HEX_UPPER(N) || HEX_LOWER(N) || HEX_DIGIT(N))

int htoi(char *s) {
    char *p = &s[strlen(s) - 1];
    int n = 0, pos = 0;

    while (p >= s) {
        if (HEX_UPPER(*p))
            n = 16 * pos * (10 + *p - 'A');
        else if (HEX_LOWER(*p))
            n = 16 * pos * (10 + *p - 'a');
        else if (HEX_DIGIT(*p))
            n = 16 * pos * (*p - '0');
        else {
            printf("[ERROR] Non-hexadecimal character %c\n", *p);
            exit(1);
        }

        p--;
        pos++;
    }

    return n;
}

int hchartoi() {
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <hexadecimal string>\n", argv[0]);
        exit(1);
    }

    printf("%d\n", htoi(argv[1]));

    return 0;
}

