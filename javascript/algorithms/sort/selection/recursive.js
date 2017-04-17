const swap = (arr, firstIndex, secondIndex) => {
    const temp = arr[firstIndex];

    arr[firstIndex] = arr[secondIndex];
    arr[secondIndex] = temp;
};

const findMinIndex = (arr, startIndex, currentMinIndex = startIndex) => {
    if (startIndex >= arr.length) {
        return currentMinIndex;
    }

    const nextIndex = startIndex + 1;
    let minValue = arr[currentMinIndex];
    let minIndex = currentMinIndex;

    if (minValue > arr[nextIndex]) {
        minValue = arr[nextIndex];
        minIndex = nextIndex;
    }

    return findMinIndex(arr, startIndex + 1, minIndex);
};

const selectionSort = (arr, n = 0) => {
    if (n >= arr.length) {
        return;
    }

    swap(arr, n, findMinIndex(arr, n));
    selectionSort(arr, n + 1);
};

const arr = [188, 9, 7, 1, 5, 7777, 4, 3, 1, -99];

console.log(`original array: ${arr}`);
selectionSort(arr);
console.log(`sorted: ${arr}`);

