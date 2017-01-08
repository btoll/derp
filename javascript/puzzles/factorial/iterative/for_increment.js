const factorial = n => {
    let j = 1;

    for (let i = 1; i <= n; i++) {
        j *= i;
    }

    return j;
};

console.log(factorial(6));

