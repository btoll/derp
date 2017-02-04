#include "../binaryTree.c"

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

int n = 0;
void inorder(int tree[], struct node *root) {
    if (!root)
        return;

    if (root->left)
        inorder(tree, root->left);

    *(tree + n) = root->value;
    n++;

    if (root->right)
        inorder(tree, root->right);

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

    inorder(tree, root);

    printf("{ ");
    for (n = 0; n < 8; n++, *(tree + n)) {
        printf("%d ", tree[n]);
    }
    printf(" }");

    return 0;
}

