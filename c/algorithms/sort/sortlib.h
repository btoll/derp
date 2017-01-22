#include <stdio.h>

void printArray(char *msg, int *array, int len) {
    unsigned int short i;

    printf("\n%s\n\n", msg);
    printf("\t[ ");

    for (i = 0; i < len; i++) {
        if (i == (len - 1)) {
            printf("%d", array[i]);
        } else {
            printf("%d, ", array[i]);
        }
    }

    printf(" ]\n");
}

