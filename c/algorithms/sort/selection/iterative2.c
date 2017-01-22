#include <stdio.h>

int array[10] = { 188, 9, 7, 1, 5, 7777, 4, 3, 1, -99 };
unsigned int short len = sizeof(array) / sizeof(int);

void printArray(char *msg) {
    unsigned int short i;

    printf("\n%s\n\n", msg);
    printf("\t[");

    for (i = 0; i < len; i++) {
        printf("%d, ", array[i]);
    }

    printf("]\n");
}

void swap(unsigned int i, unsigned int j) {
    unsigned int short tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;
}

unsigned int short findMinIndex(unsigned int short i) {
    unsigned int short j;
    unsigned int short minIndex = i;
    unsigned int short minValue = array[i];

    for (j = i + 1; j < len; j++) {
        if (array[j] < minValue) {
            minValue = array[j];
            minIndex = j;
        }
    }

    return minIndex;
}

void selectionSort() {
    unsigned int short i;

    for (i = 0; i < len; i++) {
        swap(i, findMinIndex(i));
    }
}

void main(void) {
    printArray("Before sort:");
    selectionSort();
    printArray("After sort:");
}

