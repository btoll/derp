#include <string.h>
#include "../sortlib.h"

int array[10] = { 188, 9, 7, 1, 5, 7777, 4, 3, 1, -99 };
unsigned int short len = sizeof(array) / sizeof(int);

void merge(unsigned int short p, unsigned int short q, unsigned int short r) {
    int lowHalfLen = q - p + 1;
    int highHalfLen = r - q;

    int lowHalf[lowHalfLen];
    int highHalf[highHalfLen];

    int i = 0, j = 0, k = p;

    memcpy(lowHalf, array + p, lowHalfLen * sizeof(int));
    memcpy(highHalf, array + q + 1, highHalfLen * sizeof(int));

    while (i < lowHalfLen && j < highHalfLen) {
        if (lowHalf[i] < highHalf[j]) {
            array[k] = lowHalf[i++];
        } else {
            array[k] = highHalf[j++];
        }

        k++;
    }

    while (i < lowHalfLen) {
        array[k++] = lowHalf[i++];
    }

    while (j < highHalfLen) {
        array[k++] = highHalf[j++];
    }
}

int mergeSort(int p, int r) {
    if (p >= r) {
        return 0;
    }

    int q = (p + r) / 2;

    mergeSort(p, q);
    mergeSort(q + 1, r);
    merge(p, q, r);
}

void main(void) {
    printArray("Before sort:", array, len);
    mergeSort(0, len - 1);
    printArray("After sort:", array, len);
}

