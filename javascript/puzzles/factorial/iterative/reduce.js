const n = [1, 2, 3, 4, 5, 6].reduce((acc, curr) => (
    acc *= curr, acc
), 1);

console.log(n);

