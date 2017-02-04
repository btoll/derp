#include "../binaryTree.c"

// Perform a preorder traversal of the BST where the result is: { 100, 50, 25, 75, 150, 125, 110, 175 }
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

int n = 0;
void preorder(int tree[], struct node *root) {
    if (!root)
        return;

    *(tree + n) = root->value;
    n++;

    if (root->left)
        preorder(tree, root->left);

    if (root->right)
        preorder(tree, root->right);

    return;
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

    preorder(tree, root);

    printf("{ ");
    for (n = 0; n < 8; n++, *(tree + n)) {
        printf("%d ", tree[n]);
    }
    printf(" }");

    return 0;
}

