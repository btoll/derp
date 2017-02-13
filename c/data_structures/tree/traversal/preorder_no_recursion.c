#include "../binaryTree.c"
#include "../../../include/nodestack.c"

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


int *preorder(struct node *root) {
    struct stack *stack = initStack();
    struct node *curr;

    push(&stack, root);

    while (stack->size > 0) {
        curr = pop(&stack);

        printf("%d\n", curr->value);

        if (curr->right)
            push(&stack, curr->right);

        if (curr->left)
            push(&stack, curr->left);
    }
}

int main(void) {
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

    preorder(root);

    return 0;
}

