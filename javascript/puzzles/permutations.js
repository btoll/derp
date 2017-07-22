const permutate = arr => {
    const res = [];

    const permute = (arr, memo = []) => {
        if (!arr.length) {
            res.push(memo);
        }

        for (let i = 0, len = arr.length; i < len; i++) {
            let [begin, ch, end] = [
                arr.slice(0, i),
                arr[i],
                arr.slice(i + 1)
            ];

            permute(
                [...begin, ...end],
                [...memo, ch]
            );
        }
    };

    permute(arr.split(''));

    return res;
};

console.log(
    permutate('fool')
);

