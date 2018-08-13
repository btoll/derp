const insert = (arr, rightIndex, value) => {
    if (rightIndex < 0 || arr[rightIndex] < value) {
        return arr[rightIndex + 1] = value;
    }

    arr[rightIndex + 1] = arr[rightIndex];

    return insert(arr, rightIndex - 1, value);
};

const insertionSort = (arr, n = 1) => {
    if (n >= arr.length) {
        return;
    }

    insert(arr, n - 1, arr[n]);
    insertionSort(arr, n + 1);
};

// const arr = [3, 5, 7, 11, 13, 2, 9, 6];
const arr = [3, 8, 7, 11, 13, 22, 69, -5];

console.log(`original array: ${arr}`);
insertionSort(arr);
console.log(`sorted array: ${arr}`);

