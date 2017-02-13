#include "binaryTree.c"

// Perform a inorder traversal of the BST where the result is: { 25, 50, 75, 100, 110, 125, 150, 175 }
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

int max(int m, int n) {
    return m > n ? m : n;
}

int getHeight(struct node *node) {
    if (node == NULL)
        return 0;
//     if (node->left) {
//         getHeight(node->left, ++n);
//     }

//     if (node->right) {
//         getHeight(node->right, n++);
//     }

//     return n;
    return 1 + max(getHeight(node->left), getHeight(node->right));
}

int main(void) {
    int tree[8];

    struct node *root = makeNode(100);
    struct node *a = makeNode(50);
    struct node *b = makeNode(150);
    struct node *c = makeNode(25);
    struct node *d = makeNode(75);
    struct node *e = makeNode(125);
    struct node *f = makeNode(175);
    struct node *g = makeNode(110);

    root->left = a;
    root->right = b;

    a->left = c;
    a->right = d;

    b->left = e;
    b->right = f;

    e->left = g;

    printf("%d\n", getHeight(root));

    return 0;
}

