#!/usr/bin/env node

const P1 = process.argv[2];
const P2 = process.argv[3];

if (!P1 || !P2) {
    console.log(`Usage: ${process.argv[1]} [Prime 1] [Prime 2]`);
    return;
}

// phi(N) = phi(P1)*phi(P2)

console.log(`phi(${P1 * P2}) = ${(P1 - 1) * (P2 - 1)}`);

