/* eslint-disable no-console */

const reAnchorMatch = /^(\w).*\1$/;

const isPalindrome = str => {
    if (str.length < 2) {
        return true;
    }

    if (str.match(reAnchorMatch)) {
        return isPalindrome(str.slice(1, str.length - 1));
    }

    return false;
};

console.log(isPalindrome('ccbabccz'));
console.log(isPalindrome('zccbabccz'));

