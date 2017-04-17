const reverse = s => {
    const a = s.split('');
    let i, j, c;

    for (i = 0, j = a.length - 1; i < j; i++, j--) {
        c = a[i];
        a[i] = a[j];
        a[j] = c;
    }

    return a.join('');
};

const toString = n => {
    let i = '';

    do {
        i += String.fromCodePoint((n % 10) + '0'.codePointAt(0));
    } while ((n = n / 10 >> 0) > 0);

    return reverse(i);
};

console.log(
    toString(7115)
);

