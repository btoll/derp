#include "../sortlib.h"

int array[] = { 188, 9, 7, 1, 5, 7777, 4, 3, 1, -99, 10, 13 };
unsigned int short len = sizeof(array) / sizeof(int);

void swap(int i, int j) {
    int tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;
}

int partition(int p, int r) {
    int j = p;
    int q = p;
    int pivot = array[r];

    while (j < r) {
        if (array[j] <= pivot) {
            swap(q, j);
            q++;
        }

        j++;
    }

    swap(q, r);

    return q;
}

int quickSort(int p, int r) {
    if (p >= r) {
        return 0;
    }

    int pivot = partition(p, r);

    quickSort(p, pivot - 1);
    quickSort(pivot + 1, r);
}

void main(void) {
    printArray("Before sort:", array, len);
    quickSort(0, len -1);
    printArray("After sort:", array, len);
}

