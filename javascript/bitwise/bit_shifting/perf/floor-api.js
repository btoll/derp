const n = process.argv[2];

console.log(`Math.floor, ${n} iterations`);

console.time('floor-api');

for (let i = 0; i < n; i++) {
    Math.floor(5.5);
}

console.timeEnd('floor-api');

