/* eslint-disable no-console */
//
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

const compute = (g, e, p) => {
    const shiftedRight = e.shiftRight(1);

    if (shiftedRight.lt(2)) {
        return g.pow(e).mod(p);
    }

    return bignum(
        compute(g, shiftedRight, p)
        * compute(g, shiftedRight, p)
    ).mod(p);
};

const result = compute(bignum(7), bignum(256), bignum(13));
console.log(result);

