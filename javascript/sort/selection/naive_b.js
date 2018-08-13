const swap = (arr, first, second) => {
    const temp = arr[first];

    arr[first] = arr[second];
    arr[second] = temp;
};

const selectionSort = arr => {
    for (let i = 0, len = arr.length; i < len; i++) {
        for (let j = i + 1; j < len; j++) {
            if (arr[j] < arr[i]) {
                swap(arr, j, i);
            }
        }
    }

    return arr;
};

console.log(selectionSort([188, 9, 7, 1, 5, 7777, 4, 3, 1, -99]));

