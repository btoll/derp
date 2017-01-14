#include <stdio.h>

void truthTable(unsigned int short n) {
    int i, bit_a, bit_b;

    if (!n) {
        printf("Bitwise (inclusive) OR\n\n");
    } else if (n == 1) {
        printf("Bitwise AND\n\n");
    } else if (n == 2) {
        printf("Bitwise (exclusive) XOR\n\n");
    }

    for (i = 0; i < 4; i++) {
        bit_a = (i & 2) / 2;
        bit_b = i & 1;

        // Logic gates.
        if (!n) {
            printf("\t%d | %d = %d\n", bit_a, bit_b, bit_a | bit_b);
        } else if (n == 1) {
            printf("\t%d & %d = %d\n", bit_a, bit_b, bit_a & bit_b);
        } else if (n == 2) {
            printf("\t%d ^ %d = %d\n", bit_a, bit_b, bit_a ^ bit_b);
        }
    }

    printf("-----------------------------\n");
}

void main() {
    printf("-----------------------------\n");
    truthTable(1);
    printf("\n");
    truthTable(0);
    printf("\n");
    truthTable(2);
}

