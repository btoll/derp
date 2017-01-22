#include "../sortlib.h"

int array[10] = { 188, 9, 7, 1, 5, 7777, 4, 3, 1, -99 };
unsigned int short len = sizeof(array) / sizeof(int);

void insert(unsigned int short dropIndex) {
    int short previous = dropIndex - 1;
    int key = array[dropIndex];

    while (previous > -1 && key < array[previous]) {
        // Shift right.
        array[dropIndex] = array[previous];

        dropIndex -= 1;
        previous -= 1;
    }

    array[dropIndex] = key;
}

void insertionSort() {
    unsigned int short i;

    for (i = 1; i < len; i++) {
        insert(i);
    }
}

void main(void) {
    printArray("Before sort:", array, len);
    insertionSort();
    printArray("After sort:", array, len);
}

