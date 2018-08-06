#!/usr/bin/env node

const M = process.argv[2];

if (!module.parent && !M) {
    console.log(`Usage: ${process.argv[1]} [number_to_factor]`);
    return;
}

const factor = N =>
    [...Array(N * 1).keys()]
    .map(i => i + 1)
    .filter(i =>
        N % i === 0
    );

// Report the result if module is run directly and not included as part of another script.
// If the module has a parent it means it was included into another script.
if (!module.parent) {
    console.log(factor(M).join(','));
}

module.exports = factor;

