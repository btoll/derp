/* eslint-disable no-console */

const arr = [14, 7, 3, 12, 9, 11, 6, 2];
// const arr = [14, 7, 3];

// const merge = (leftArray, rightArray) => {
// };

const mergeSort = (arr) => {
    if (arr.length < 2) {
        return arr;
    }

    const mid = Math.floor(arr.length / 2);

    mergeSort(arr.slice(0, mid));
    mergeSort(arr.slice(mid));
//    return merge(
//    );
};

mergeSort(arr);
console.log(arr);

