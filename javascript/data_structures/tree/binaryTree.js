'use strict';

const makeNode = (l, r, val) => {
    let left = l;
    let right = r;
    let value = val;

    const node = {};

    Object.defineProperties(node, {
        left: {
            enumerable: false,
            get: () => left,
            set: v => left = v
        },
        right: {
            enumerable: false,
            get: () => right,
            set: v => right = v
        },
        value: {
            enumerable: false,
            get: () => value,
            set: v => value = v
        }
    });

    return node;
};

module.exports = makeNode;

