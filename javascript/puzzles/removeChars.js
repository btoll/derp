// Remove all vowels to produce the sentence 'Bttl f th Vwls: Hw vs. Grzny'.

const removeChars = (s, toRemove) => {
    const vowels = toRemove.split('').reduce(
        (acc, curr) =>
            (acc[curr] = 1, acc)
        , {}
    );

    return s.split('').filter(
        c => !vowels[c]
    ).join('');
};

console.log(
    removeChars('Battle of the Vowels: Hawaii vs. Grozny', 'aeiou')
);

