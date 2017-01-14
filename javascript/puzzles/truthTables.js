const lineSeparator = '\n-----------------------------------------------------------\n';

const table = {
    '&': {
        text: 'AND',
        fn: (a, b) => a & b
    },
    '|': {
        text: '(inclusive) OR',
        fn: (a, b) => a | b
    },
    '^': {
        text: '(exclusive) XOR',
        fn: (a, b) => a ^ b
    }
};

const makeTruthTable = operator => {
    console.log(lineSeparator);
    console.log(`Bitwise ${table[operator].text}\n`);

    [0, 1, 2, 3].forEach(i => {
        const bitA = (i & 2) / 2;
        const bitB = i & 1;

        console.log(`\t${bitA} ${operator} ${bitB} => ${table[operator].fn(bitA, bitB)}`);
    });
};

makeTruthTable('&');
makeTruthTable('|');
makeTruthTable('^');
console.log(lineSeparator);

