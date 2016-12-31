//
// Polyfill Math.pow!
//
const pow = (x, n) => {
    if (n === 0) {
        // Math.pow(x, 0);
        return 1;
    }

    if (n < 0) {
        // For negative numbers, recursively calculate x^-n where n is a positive number.
        //
        //      x^n = 1 / x^-n
        //
        return 1 / pow(x, -n);
    } else if (n % 2 === 0) {
        // Here we only need to calculate one term and then multiply it by itself.
        //
        //      x^n = ( x^n / 2 ) * ( x^n / 2 )
        //
        // return Math.pow(
        //     pow(x, n / 2), 2
        // );
        //
        const p = pow(x, n / 2);
        return p * p;
    } else {
        // For odd numbers, recursively calculate x^n - 1.
        //
        //      x^n = (x^n-1) * x
        //
        //      2^7 = (2^7-1) * 2
        //
        return pow(x, n - 1) * x;
    }
};

console.log(pow(2, -10));
console.log(pow(2, -9));
console.log(pow(2, -8));
console.log(pow(2, -7));
console.log(pow(2, -6));
console.log(pow(2, -5));
console.log(pow(2, -4));
console.log(pow(2, -3));
console.log(pow(2, -2));
console.log(pow(2, -1));
console.log(pow(2, 0));
console.log(pow(2, 1));
console.log(pow(2, 2));
console.log(pow(2, 3));
console.log(pow(2, 4));
console.log(pow(2, 5));
console.log(pow(2, 6));
console.log(pow(2, 7));
console.log(pow(2, 8));
console.log(pow(2, 9));
console.log(pow(2, 10));

