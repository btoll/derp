const isInArray = (target, arr) => {
    const min = 0;
    const max = arr.length - 1;

    if (max < min) {
        return false;
    }

    const guess = Math.floor((min + max) / 2);

    if (arr[guess] === target) {
        return true;
    }

    return isInArray(target,
        target < arr[guess] ?
            arr.slice(0, guess) :
            arr.slice(guess + 1)
    );
};

console.log(`is in array: ${isInArray(1, [1, 3, 5, 7, 9])}`);
console.log(`is in array: ${isInArray(3, [1, 3, 5, 7, 9])}`);
console.log(`is in array: ${isInArray(66, [1, 3, 5, 7, 9])}`);
console.log(`is in array: ${isInArray(5, [1, 3, 5, 7, 9])}`);
console.log(`is in array: ${isInArray(7, [1, 3, 5, 7, 9])}`);
console.log(`is in array: ${isInArray(9, [1, 3, 5, 7, 9])}`);

