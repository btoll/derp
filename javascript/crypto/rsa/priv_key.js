#!/usr/bin/env node

const e = process.argv[2] * 1;
const mod = process.argv[3] * 1;

if (!e || !mod) {
    console.log(`Usage: ${process.argv[1]} [e] [modulus]`);
    return;
}

//console.log(`[[ $(echo "${e}*$\{1..${mod}\}%phi(${mod})" | bc) -eq 1 ]]`);

console.log(
    [...Array(200).keys()]
    .map(i => i + 1)
    .filter(i =>
        e * i % mod === 1
    ).join(',')
);

