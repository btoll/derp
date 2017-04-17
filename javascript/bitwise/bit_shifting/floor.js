// Faster than Math.floor(n) the greater the input, i.e., 1,000,000.
const floor = n =>
    n >> 0;

console.log(floor(11.5));
console.log(floor(20.33));
console.log(floor(Math.PI));

