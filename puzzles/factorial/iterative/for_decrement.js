const factorial = n => {
    let j = n;

    for (let i = n - 1; i > 0; i--) {
        j *= i;
    }

    return j;
};

console.log(factorial(6));

