
const getbits = (s, p, n) =>
    s >> (p + 1 - n) & ~(~0 << n);

const asbits = s => {
    const a = [];

    // Let's print out 4 space-delimited bytes.
    for (let i = 15; i >= 0; i--) {
        getbits(s, i, 1) ? a.push('1') : a.push('0');

        if (i % 4 === 0) {
            a.push(' ');
        }
    }

    return a.join('');
};

if (process.argv.length < 3) {
    console.log(`Usage: ${process.argv[1]} <num>`);
} else {
    console.log(asbits(process.argv[2]));
}

