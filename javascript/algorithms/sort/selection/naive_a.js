const swap = (arr, n) => {
    const temp = arr[n];

    arr[n] = arr[n - 1];
    arr[n - 1] = temp;
};

const selectionSort = arr => {
    for (let i = 0, len = arr.length; i < len; i++) {
        for (let j = 1; j < len; j++) {
            if (arr[j] < arr[j - 1]) {
                swap(arr, j);
            }
        }
    }

    return arr;
};

console.log(selectionSort([188, 9, 7, 1, 5, 7777, 4, 3, 1, -99]));

