/* eslint-disable no-console */

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

// const arr = [3, 5, 7, 11, 13, 2, 9, 6];
const arr = [3, 5, 7, 11, 13, 22, 69, -5];

console.log(`original array: ${arr}`);
insertionSort(arr);
console.log(`sorted array: ${arr}`);

