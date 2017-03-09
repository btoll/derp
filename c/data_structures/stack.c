#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *next;
    void *data;
};

int push(struct node **stack, void *data) {
    struct node *newNode;

    if (!(newNode = malloc(sizeof(struct node)))) {
        fprintf(stderr, "Could not allocate memory for new node!");
        exit(1);
    }

    if (!*stack) {
        newNode->next = NULL;
    } else {
        newNode->next = *stack;
    }

    newNode->data = data;
    *stack = newNode;
}

struct node *pop(struct node **stack) {
    struct node *popped = *stack;

    *stack = popped->next;
    free(popped);

    return popped;
}

int main(void) {
    struct node *stack = NULL;

    push(&stack, "hello, world");
    push(&stack, (int *) 45);
    printf("%d\n", stack->data);

    pop(&stack);
    printf("%s\n", stack->data);

    pop(&stack);
    printf("%p\n", stack);

    return 0;
}

