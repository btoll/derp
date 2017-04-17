const fibonacci = (n, cache = {}) => {
    if (n < 2) {
        return n;
    }

    if (cache[n]) {
        return cache[n];
    } else {
        return cache[n] = fibonacci(n - 2, cache) + fibonacci(n - 1, cache);
    }
};

console.log(fibonacci(75));

