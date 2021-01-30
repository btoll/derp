#!/usr/bin/env node

// This tries to find the modular multiplicative inverse.

const e = process.argv[2] * 1;
const mod = process.argv[3] * 1;
const bound = process.argv[4] * 1;

if (!e || !mod || !bound) {
    console.log(`Usage: ${process.argv[1]} [e] [modulus] [bound]`);
    return;
}

//console.log(`[[ $(echo "${e}*$\{1..${mod}\}%phi(${mod})" | bc) -eq 1 ]]`);

console.log(
    [...Array(bound).keys()]
    .map(i => i + 1)
    .filter(i =>
        e * i % mod === 1
    ).join(',')
);

