#!/usr/bin/env node

const factor = require('./factor');

const M = process.argv[2];
const N = process.argv[3];

if (!M || !N) {
    console.log(`Usage: ${process.argv[1]} [number_to_factor] [number_to_factor]`);
    return;
}

const sorter = (a, b) => {
    if (a < b) {
        return -1;
    } else if (a > b) {
        return 1;
    } else {
        return 0;
    }
};

console.log(
    Array.from(
        new Set(
            [...factor(M),
            ...factor(N)
            ]
        )
    ).sort(sorter)
);

