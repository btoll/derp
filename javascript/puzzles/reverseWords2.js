const reverse = (s, m, n) => {
    const a = s.slice(m, n).split('');

    for (let i = 0, j = a.length - 1; i < j; i++, j--) {
        let c = a[i];
        a[i] = a[j];
        a[j] = c;
    }

    return a.join('');
};

const reverseWords = s => {
    const size = s.length;
    let curPos = 0, beginWord = 0;
    let reversedWords = [];

    s = reverse(s, 0, size);

    while (curPos < size) {
        for (; s[curPos] !== ' ' && curPos < size; curPos++)
            ;

        reversedWords.push(reverse(s, beginWord, curPos));
        beginWord = ++curPos;
    }

    return reversedWords.join(' ');
};

console.log(
    reverseWords('Do or do not, there is no try.')
);

