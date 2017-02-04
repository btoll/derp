#include "../binaryTree.c"

// Perform a postorder traversal of the BST where the result is: { 25, 75, 50, 110, 125, 175, 150, 100 }
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
void postorder(int tree[], struct node *root) {
    if (!root)
        return;

    if (root->left)
        postorder(tree, root->left);

    if (root->right)
        postorder(tree, root->right);

    *(tree + n) = root->value;
    n++;

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

    postorder(tree, root);

    printf("{ ");
    for (n = 0; n < 8; n++, *(tree + n)) {
        printf("%d ", tree[n]);
    }
    printf(" }");

    return 0;
}

