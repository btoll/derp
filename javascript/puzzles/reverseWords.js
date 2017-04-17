const reverseWords = s => {
    const words = s.split(' ');
    let tmp;

    for (let i = 0, j = words.length - 1; i < j; i++, j--) {
        tmp = words[i];
        words[i] = words[j];
        words[j] = tmp;
    }

    return words.join(' ');
};

console.log(
    reverseWords('Do or do not, there is no try.')
);

