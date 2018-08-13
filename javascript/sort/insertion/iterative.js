/* eslint-disable no-console */

// Since the important index is the `rightIndex` (which is always to the left of where we'll drop our `key`),
// this must be re-adjusted right before the `key` insertion.

const insert = (arr, rightIndex, value) => {
    let n = rightIndex;

    while (arr[n] > value) {
        arr[n + 1] = arr[n];
        n--;
    }

    arr[++n] = value;
};

const insertionSort = arr => {
    for (let i = 1, len = arr.length; i < len; i++) {
        insert(arr, i - 1, arr[i]);
    }
};

const arr = [5, 3, 11, 7, -5, 13, 2, 9, 6];

console.log(`original array: ${arr}`);
insertionSort(arr);
console.log(`sorted array: ${arr}`);

