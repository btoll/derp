const swap = (array, firstIndex, secondIndex) => {
    const tmp = array[firstIndex];
    array[firstIndex] = array[secondIndex];
    array[secondIndex] = tmp;
};

// Create 4 groupings in the array passed to partition():
//
//      - array[p..q-1] = elements <= pivot
//      - array[q..j-1] = elements > pivot
//      - array[j..r-1] = elements yet to examine (unknown but shrinking as `j` is incremented)
//      - array[r] = the pivot
//
// Initially, both `j` and `q` are set equal to `p`.
// Finally, when `j === r`, swap `r` (the pivot) with `q`.
//
const partition = (array, p, r) => {
    let j = p;
    let q = p;
    let pivot = array[r];

    while (j < r) {
        if (array[j] <= pivot) {
            // Swap out the elements and shift the eventual pivot index to the right.
            swap(array, q, j);
            q++;
        }

        j++;
    }

    // Finally, swap the pivot into its new index between the 'less than or equal to' elements (left)
    // and the 'greater than' elements (right).
    swap(array, q, r);

    return q;
};

const quickSort = (array, p, r) => {
    if (p >= r) {
        return array;
    }

    const pivot = partition(array, p, r);

    quickSort(array, p, pivot - 1);
    quickSort(array, pivot + 1, r);

    return array;
};

const array = [9, 7, 5, 11, -5, 12, 2, -7, 14, 3, 10, 6];

console.log('array to sort:', array, '\n');
console.log('      results:', quickSort(array, 0, array.length - 1));

