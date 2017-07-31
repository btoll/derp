// Bubble sort has to iterate n - 1 times, where n is the number of elements to be sorted.
// We can optimize this by decreasing the number of iterations by one each time, since the
// larger elements that have been 'bubbled up' to the end of the array are already sorted.
const bubbleSort = a => {
    let passes = a.length;

    while (passes > 0) {
        for (let i = 1; i < passes; i++) {
            if (a[i] < a[i - 1]) {
                // Swap.
                let tmp = a[i];

                a[i] = a[i - 1];
                a[i - 1] = tmp;
            }
        }

        passes--;
    }

    return a;
};

const arr = [5, 3, 11, 7, -5, 13, 2, 9, 6];

console.log('bubbleSort', bubbleSort(arr));

