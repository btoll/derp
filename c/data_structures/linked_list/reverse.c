#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *next;
    int data;
};

struct node *addNode(struct node **head, int data) {
    struct node *newNode;

    if (!(newNode = malloc(sizeof(struct node)))) {
        fprintf(stderr, "Could not allocate memory for new node!");
        exit(1);
    }

    if (*head == NULL) {
        newNode->data = data;
        newNode->next = NULL;
        *head = newNode;
    } else {
        struct node *curr = *head;

        while (curr->next) {
            curr = curr->next;
        }

        curr->next = newNode;
        newNode->data = data;
        newNode->next = NULL;
    }

    return newNode;
}

void printNodes(struct node *head) {
    struct node *node = head;

    while (node) {
        printf("node->data %d\n", node->data);
        node = node->next;
    }
}

void reverse(struct node **head) {
    if (!*head)
        return;

    struct node *tmp;
    struct node *prev = NULL;
    struct node *node = *head;

    while (node) {
        tmp = node->next;
        node->next = prev;
        prev = node;
        node = tmp;
    }

    *head = prev;
}

int main(void) {
    struct node *head = NULL;

    addNode(&head, 0);
    addNode(&head, 1);
    addNode(&head, 2);
    addNode(&head, 3);
    addNode(&head, 4);
    addNode(&head, 5);
    addNode(&head, 6);
    addNode(&head, 7);
    addNode(&head, 8);
    addNode(&head, 9);
    addNode(&head, 10);
    addNode(&head, 11);
    addNode(&head, 12);
    addNode(&head, 13);
    addNode(&head, 14);

    printNodes(head);
    reverse(&head);
    printNodes(head);

    return 0;
}

