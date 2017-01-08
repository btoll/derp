const reMatchAnchors = /^(\w).*\1$/;

const isPalindrome = s => {
    if (s.length < 2) {
        return true;
    }

    if (reMatchAnchors.test(s)) {
        return isPalindrome(s.slice(1, -1));
    }

    return false;
};

console.log('rotetor', isPalindrome('rotetor'));
console.log('motor', isPalindrome('motor'));
console.log('b', isPalindrome('b'));
console.log('', isPalindrome(''));
console.log('rater', isPalindrome('rater'));

