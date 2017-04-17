const reverse = s => {
    const a = s.split('');
    let tmp;

    for (let i = 0, j = a.length - 1; i < j; i++, j--) {
        tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
    }

    return a.join('');
};

console.log(reverse('Hello, world!'));

