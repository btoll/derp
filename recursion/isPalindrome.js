/* eslint-disable no-console */

const isPalindrome = str => {
    if (str.length < 2) {
        return true;
    }

    if (str.match(/^(\w).*\1$/)) {
        return isPalindrome(str.slice(1, str.length - 1));
    }

    return false;
};

console.log(isPalindrome('ccbabccz'));
console.log(isPalindrome('zccbabccz'));

