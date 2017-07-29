'use strict';
//
//
//              __ 100 __
//             /         \
//         50              150
//       /    \          /     \
//     25      75      125     175
//                   /
//                 110
//
//

const makeNode = require('../binaryTree');

// Perform a preorder traversal of the BST where the result is: { 100, 50, 25, 75, 150, 125, 110, 175 }
const preorder = (root, nodes) => {
    if (!root) {
        return nodes;
    }

    nodes.push(root.value);

    if (root.left) {
        preorder(root.left, nodes);
    }

    if (root.right) {
        preorder(root.right, nodes);
    }

    return nodes;
};

// Perform a inorder traversal of the BST where the result is: { 25, 50, 75, 100, 110, 125, 150, 175 }
const inorder = (root, nodes) => {
    if (!root) {
        return nodes;
    }

    if (root.left) {
        inorder(root.left, nodes);
    }

    nodes.push(root.value);

    if (root.right) {
        inorder(root.right, nodes);
    }

    return nodes;
};

// Perform a postorder traversal of the BST where the result is: { 25, 75, 50, 110, 125, 175, 150, 100 }
const postorder = (root, nodes) => {
    if (!root) {
        return nodes;
    }

    if (root.left) {
        postorder(root.left, nodes);
    }

    if (root.right) {
        postorder(root.right, nodes);
    }

    nodes.push(root.value);

    return nodes;
};
const root = makeNode(null, null, 100);
const a = makeNode(null, null, 50);
const b = makeNode(null, null, 150);
const c = makeNode(null, null, 25);
const d = makeNode(null, null, 75);
const e = makeNode(null, null, 125);
const f = makeNode(null, null, 175);
const g = makeNode(null, null, 110);

root.left = a;
root.right = b;

a.left = c;
a.right = d;

b.left = e;
b.right = f;

e.left = g;

console.log('preorder', preorder(root, []));
console.log('inorder', inorder(root, []));
console.log('postorder', postorder(root, []));


