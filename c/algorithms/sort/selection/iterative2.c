#include "../sortlib.h"

int array[10] = { 188, 9, 7, 1, 5, 7777, 4, 3, 1, -99 };
unsigned int short len = sizeof(array) / sizeof(int);

void swap(unsigned int i, unsigned int j) {
    unsigned int short tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;
}

unsigned int short findMinIndex(unsigned int short i) {
    unsigned int short j = i + 1;
    unsigned int short minIndex = i;
    unsigned int short minValue = array[i];

    for (; j < len; j++) {
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
    printArray("Before sort:", array, len);
    selectionSort();
    printArray("After sort:", array, len);
}

