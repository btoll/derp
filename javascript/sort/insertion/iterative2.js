// This version is different from iterative.js in that the important index is the `dropIndex` rather than the `rightIndex`.
// This means that we don't have to increment the index when we insert the `key` value.
const insert = (array, dropIndex) => {
    const key = array[dropIndex];
    let previous = dropIndex - 1;

    while (key < array[previous]) {
        // Shift right.
        array[dropIndex] = array[previous];

        // Update the indices.
        dropIndex--;
        previous--;
    }

    // Insert our sorted value.
    array[dropIndex] = key;
};

const insertionSort = array => {
    for (let i = 1, len = array.length; i < len; i++) {
        insert(array, i);
    }

    return array;
};

const array = [5, 3, 11, 7, -5, 13, 2, 9, 6];

console.log(`original array: ${array}`);
insertionSort(array);
console.log(`sorted array: ${array}`);

