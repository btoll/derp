#!/usr/bin/env node

const uniq = (v, i, arr) =>
    arr.indexOf(v) === i;

console.log(
    [1, 2, 3, 4, 3, 2, 1]
    .filter(uniq)
);

