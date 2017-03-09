#include <stdio.h>
#include <stdlib.h>
#include "nodestack.h"

struct stack{
    struct frame *top;
    unsigned size;
};

struct frame {
    struct frame *next;
    struct node *node;
};

struct stack *initStack(void) {
    struct stack *newStack;

    if (!(newStack = malloc(sizeof(struct stack)))) {
        fprintf(stderr, "Could not allocate memory for new stack!");
        exit(1);
    }

    newStack->top = NULL;
    newStack->size = 0;

    return newStack;
}

void push(struct stack **stack, struct node *node) {
    struct frame *newFrame;
    struct frame *oldTop;

    if (!(newFrame = malloc(sizeof(struct frame)))) {
        fprintf(stderr, "Could not allocate memory for new frame!");
        exit(1);
    }

    if ((*stack)->top == NULL)
        newFrame->next = NULL;
    else {
        oldTop = (*stack)->top;
        newFrame->next = oldTop;
    }

    (*stack)->top = newFrame;
    (*stack)->size = (*stack)->size + 1;

    newFrame->node = node;
}

struct node *pop(struct stack **stack) {
    struct frame *oldFrame = (*stack)->top;
    struct node *oldNode;

    (*stack)->top = oldFrame->next;
    oldNode = oldFrame->node;

    (*stack)->size = (*stack)->size - 1;
    free(oldFrame);

    return oldNode;
}

