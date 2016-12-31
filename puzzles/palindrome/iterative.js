const reMatchAnchors = /^(\w).*\1$/;

const isPalindrome = s => {
    while (reMatchAnchors.test(s)) {
        s = s.slice(1, -1);
    }

    if (s.length < 2) {
        return true;
    }

    return false;
};

console.log('rotetor', isPalindrome('rotetor'));
console.log('motor', isPalindrome('motor'));
console.log('b', isPalindrome('b'));
console.log('', isPalindrome(''));
console.log('rater', isPalindrome('rater'));

