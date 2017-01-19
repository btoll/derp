'use strict';

const binary = n => {
    let mask = 0xff000000;
    let shift = Math.pow(256, 3);
    let bits = '';

    for (let byteIterator = 0; byteIterator < 4; byteIterator++) {
        // Isolate each byte.
        let byte = (n & mask) / shift;

        bits += ' ';

        for (let bitIterator = 0; bitIterator < 8; bitIterator++) {
            if (byte & 0x80) {
                bits += '1';
            } else {
                bits += '0';
            }

            byte *= 2;
        }

        mask /= 256;
        shift /= 256;
    }

    return bits;
};

console.log(binary(1));
console.log(binary(2));
console.log(binary(4));
console.log(binary(8));
console.log(binary(16));
console.log(binary(32));
console.log(binary(64));
console.log(binary(128));
console.log(binary(256));
console.log(binary(512));
console.log(binary(1024));
console.log(binary(2048));
console.log(binary(4096));
console.log(binary(8192));
console.log(binary(16384));
console.log(binary(32768 * 1));
console.log(binary(32768 * 2));
console.log(binary(32768 * 4));
console.log(binary(32768 * 8));
console.log(binary(32768 * 16));
console.log(binary(32768 * 32));
console.log(binary(32768 * 64));
console.log(binary(32768 * 128));
console.log(binary(32768 * 256));
console.log(binary(32768 * 512));
console.log(binary(32768 * 1024));
console.log(binary(32768 * 2048));
console.log(binary(32768 * 4096));
console.log(binary(32768 * 8192));
console.log(binary(32768 * 16384));
console.log(binary(32768 * 32768));
console.log(binary(32768 * 32768 * 1));
console.log(binary(32768 * 32768 * 2));

console.log(binary(0xffffffff));

