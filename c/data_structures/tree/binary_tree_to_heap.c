#include "binaryTree.c"

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

int count(struct node *node, int n) {
    if (!node)
        return n;

    n++;

    if (node->left)
        n = count(node->left, n);

    if (node->right)
        n = count(node->right, n);

    return n;
}

int preorder(struct node *node, struct node *buf, int n) {
    if (!node)
        return 0;

    *(buf + (n++)) = *node;

    if (node->left)
        n = preorder(node->left, buf, n);

    if (node->right)
        n = preorder(node->right, buf, n);

    return n;
}

void print(struct node *node) {
    if (!node)
        return;

//     *(buf + (n++)) = *node;
    printf("%d\n", node->value);
    printf("%d\n", node->right->value);

    if (node->left)
        print(node->left);

    if (node->right)
        print(node->right);
}

void arrayToHeap(struct node *buf, int size, struct node *heap) {
    int i;
    int left;
    int right;

    for (i = 0; i < size; i++) {
        left = i * 2 + 1;
        right = i * 2 + 2;

        heap[i].value = buf[i].value;

        if (buf[left].value != '\0')
            heap[i].left = buf[left].left;

        if (buf[right].value != '\0')
            heap[i].right = buf[right].right;
    }
}

int main(int argc, char **argv) {
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

    int size = count(root, 0);

    struct node *buf = malloc(size * sizeof(struct node));
    preorder(root, buf, 0);

    // Verify we have rightly constructed the array of structs.
    int i;
//     for (i = 0; i < size; i++)
// //         printf("%d\n", buf[i].value);
//         printf("%d\n", (buf + i)->value);

    struct node *heap = malloc(size * sizeof(struct node));
    arrayToHeap(buf, size, heap);

//     size = count(heap, 0);
//     printf("%d\n", size);

//     print(heap);

    printf("%d\n", heap[0].left->value);
    printf("%d\n", heap[0].right->value);

    free(buf);
    free(heap);

    return 0;
}

