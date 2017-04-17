for (let i = 0; i < 100; i++) {
    let fizzbuzz = 0;

    if (i % 3 === 0) {
        fizzbuzz = 1;
    }

    if (i % 5 === 0) {
        fizzbuzz += 2;
    }

    switch (fizzbuzz & 3) {
        case 0:
            console.log(i);
            break;
        case 1:
            console.log('fizz');
            break;
        case 2:
            console.log('buzz');
            break;
        case 3:
            console.log('fizzbuzz');
            break;
    }
}

