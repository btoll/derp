const swap = (arr, firstIndex, secondIndex) => {
    const temp = arr[firstIndex];

    arr[firstIndex] = arr[secondIndex];
    arr[secondIndex] = temp;
};

const findMinIndex = (arr, startIndex) => {
    let minValue = arr[startIndex];
    let minIndex = startIndex;

    for (let i = startIndex, len = arr.length; i < len; i++) {
        if (minValue > arr[i]) {
            minValue = arr[i];
            minIndex = i;
        }
    }

    return minIndex;
};

const selectionSort = arr => {
    for (let i = 0, len = arr.length; i < len; i++) {
        swap(arr, i, findMinIndex(arr, i));
    }

    return arr;
};

console.log(selectionSort([188, 9, 7, 1, 5, 7777, 4, 3, 1, -99]));
console.log(findMinIndex(2, [188, 9, 7, -1234, 1, 5, 7777, 4, 3, 1, -99]));

