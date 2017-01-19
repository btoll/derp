// When multiplying powers of `x`, you add the exponents:
//
//     x^a * x^b = x^a+b
//
// Therefore, if `n` is positive and even:
//
//     x^n = x^n/2 * x^n/2
//
//         - Compute x^n/2 recursively.
//         - You can get away with only doing this once and then multiplying
//           the result by itself!
//
//         2^6 = 2^6/3 * 2^6/3
//         2^6 = 2^3 * 2^3
//         2^6 = 2^3+3
//         2^6 = 2^6
//         64 = 64
//
// If `n` is positive and odd:
//
//     x^n = x^n - 1 * x
//
//     - `(n - 1)` is either 0 or positive and even.
//     - Compute (n - 1) recursively.
//
//         2^7 = 2^7-1 * 2
//         2^7 = 2^6 * 2
//         2^7 = 2^6 * 2^1
//         2^7 = 2^6+1
//         2^7 = 2^7
//         128 = 128
//
// If `n` is negative:
//
//     x^n = 1 / x^-n
//
//     - `-n` is a positive number!
//     - Compute x^-n recursively and take its reciprocal.
//       i.e., x^n = 1/x^-n


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

