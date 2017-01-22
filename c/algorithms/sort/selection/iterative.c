#include "../sortlib.h"

int array[10] = { 188, 9, 7, 1, 5, 7777, 4, 3, 1, -99 };
unsigned int short len = sizeof(array) / sizeof(int);

void swap(unsigned int i, unsigned int j) {
    unsigned int short tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;
}

void selectionSort() {
    unsigned int short i, j;

    for (i = 0; i < len; i++) {
        for (j = i + 1; j < len; j++) {
            if (array[j] < array[i]) {
                swap(i, j);
            }
        }
    }
}

void main(void) {
    printArray("Before sort:", array, len);
    selectionSort();
    printArray("After sort:", array, len);
}

