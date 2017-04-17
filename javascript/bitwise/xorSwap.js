let n = 512;
let k = 256;

const swap = () => (
    n = n ^ k,
    k = n ^ k,
    n = n ^ k
);

console.log(`(before swap) n: ${n}`, `k: ${k}`);
swap();
console.log(` (after swap) n: ${n}`, `k: ${k}`);
swap();
console.log(`      (reset) n: ${n}`, `k: ${k}`);

