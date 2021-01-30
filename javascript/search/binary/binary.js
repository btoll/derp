/**
 * Return index of found item or -1.
 */
const binarySearch = (array, target) => {
    let max = array.length - 1;
    let min = 0;

    while (true) {
        if (max < min) {
            return -1;
        }

        let guess = Math.floor((max + min) / 2);

        if (array[guess] === target) {
            return guess;
        }

        if (array[guess] < target) {
            min = guess + 1;
        } else {
            max = guess -1;
        }

    }

    return guess;
};

const primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97];
console.log(binarySearch(primes, 73));

