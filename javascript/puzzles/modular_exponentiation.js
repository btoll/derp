// Note that this only works for powers of 2!!
//
//     7^1 mod 13 = 7
//
//     7^2 mod 13 = ((7^1 mod 13) * (7^1 mod 13)) mod 13
//                = 49 mod 13
//                = 10
//
//     7^4 mod 13 = ((7^2 mod 13) * (7^2 mod 13)) mod 13
//                = (10 * 10) mod 13
//                = 100 mod 13
//                = 9
//
//     7^8 mod 13 = ((7^4 mod 13) * (7^4 mod 13)) mod 13
//                = (9 * 9) mod 13
//                = 81 mod 13
//                = 3
//
//     ...etc...
//
'use strict';

const bignum = require('bignum');

const modexp = () => {
    const cache = {};

    return function compute(g, e, p) {
        const shiftedRight = e.shiftRight(1);

        if (shiftedRight.lt(2)) {
            return g.pow(e).mod(p);
        }

        if (!cache[shiftedRight]) {
            return cache[shiftedRight] = bignum(
                compute(g, shiftedRight, p) * compute(g, shiftedRight, p)
            ).mod(p);
        } else {
            return cache[shiftedRight];
        }
    };
};

console.log(
    modexp()(
        bignum(7), bignum(1024), bignum(13)
    )
); // <BigNum 9>

console.log(
    modexp()(
        bignum(5), bignum(4096), bignum(19)
    )
); // <BigNum 5>

