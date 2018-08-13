const binarySearch = (min, max, n, tries = 1) => {
    if (tries > primes.length) {
        return [null, tries];
    }

    const guess = Math.floor(
        (max + min) / 2
    );

    if (primes[guess] === n) {
        return [n, tries];
    }

    tries += 1;

    let ma = max;
    let mi = min;

    if (primes[guess] < n) {
        mi = guess + 1;
    } else {
        ma = guess - 1;
    }

    return binarySearch(mi, ma, n, tries);
};

const primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97];
const [n, tries] = binarySearch(0, primes.length - 1, 67);
console.log(`The number is ${n}, found in ${tries} tries.`);

