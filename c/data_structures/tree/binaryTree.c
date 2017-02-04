#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *left;
    struct node *right;
    int value;
};

struct node *makeNode(int value) {
    struct node *n;
    n = malloc(sizeof(struct node));
    n->value = value;

    return n;
}

