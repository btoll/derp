// Note that this implementation assumes that every letter is only one 16-bit char!

const firstNonrepeated = s => {
    const chars = s.split('').reduce((acc, curr) => {
        if (!acc[curr]) {
            acc[curr] = 1;
        } else {
            acc[curr] = acc[curr] + 1;
        }

        return acc;
    }, {});

    for (let i = 0, len = s.length; i < len; i++) {
        if (chars[s[i]] === 1) {
            return s[i];
        }
    }

    return -1;
};

const s = 'hello, world!';
console.log(firstNonrepeated(s));

