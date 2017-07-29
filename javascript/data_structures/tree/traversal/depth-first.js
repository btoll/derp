// Same as preorder!

const makeNode = require('../binaryTree');

// Perform a preorder traversal of the BST where the result is: { 100, 50, 25, 75, 150, 125, 110, 175 }
const depthFirst = (root, nodes) => {
    if (!root) {
        return nodes;
    }

    nodes.push(root.value);

    if (root.left) {
        depthFirst(root.left, nodes);
    }

    if (root.right) {
        depthFirst(root.right, nodes);
    }

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

console.log('depth first', depthFirst(root, []));

