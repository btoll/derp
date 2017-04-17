const toInt = s => {
    let i = 0;
    let n = 0;
    let size = s.length;

    while (i < size) {
        n = 10 * n + s.charCodeAt(i++) - '0'.charCodeAt(0);
    }

    return n;
};

console.log(toInt('7115'));

