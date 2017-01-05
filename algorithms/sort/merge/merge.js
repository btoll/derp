'use strict';

const merge = (array, p, q, r) => {
    const lowHalf = array.slice(p, q + 1);
    const highHalf = array.slice(q + 1, r + 1);

    let i = 0;
    let j = 0;
    let k = p;

    while (i < lowHalf.length && j < highHalf.length) {
        if (lowHalf[i] < highHalf[j]) {
            array[k] = lowHalf[i];
            i++;
        } else {
            array[k] = highHalf[j];
            j++;
        }

        k++;
    }

    while (i < lowHalf.length) {
        array[k] = lowHalf[i];
        i++;
        k++;
    }

    while (j < highHalf.length) {
        array[k] = highHalf[j];
        j++;
        k++;
    }
};

const mergeSort = (array, p, r) => {
    if (p >= r) {
        return array;
    }

    const q = Math.floor((p + r) / 2);

    mergeSort(array, p, q);
    mergeSort(array, q + 1, r);
    merge(array, p, q, r);

    return array;
};

const array = [14, 7, 3, 12, 9, 11, 6, 2];

console.log('array to sort:', array, '\n');
console.log('      results:', mergeSort(array, 0, array.length - 1));

console.assert(array[0] === 2);
console.assert(array[array.length - 1] === 14);

