const n = process.argv[2];

console.log(`bitwise, ${n} iterations`);

console.time('floor-bitwise');

for (let i = 0; i < n; i++) {
    5.5 >> 0;
}

console.timeEnd('floor-bitwise');

