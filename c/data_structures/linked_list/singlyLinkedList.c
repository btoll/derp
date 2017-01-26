#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *next;
    int data;
};

struct node *addNode(struct node **head, int data) {
    struct node *newNode = malloc(sizeof(struct node));

    if (*head == NULL) {
        newNode->data = data;
        newNode->next = NULL;
        *head = newNode;
    } else {
        struct node *curr = *head;

        while (curr->next != NULL) {
            curr = curr->next;
        }

        curr->next = newNode;
        newNode->data = data;
        newNode->next = NULL;
    }

    return newNode;
}

struct node *getNode(struct node *head, int data) {
    struct node *found = NULL;
    struct node *link = head;

    while (link && link->data) {
        if (link->data == data) {
            found = link;
            break;
        }

        link = link->next;
    }

    return found;
}

void removeNode(struct node **head, int data) {
    struct node *link = *head;
    struct node *prev;

    while (link && link->data) {
        if (link->data == data) {
            break;
        }

        prev = link;
        link = link->next;
    }

    if (link) {
        // If the node to be removed is the HEAD.
        if (link == *head) {
            *head = link->next;
        }
        // If the node to be removed is the TAIL.
        else if (link->next == NULL) {
            prev->next = NULL;
        } else {
            prev->next = link->next;
        }

        free(link);
    }
}

void removeList(struct node **head) {
    struct node *toDelete = *head;

    while (toDelete) {
        struct node *next = toDelete->next;
        free(toDelete);
        toDelete = next;
    }
}

void main(void) {
    struct node *head = NULL;

    struct node *link = addNode(&head, 1);
    struct node *link2 = addNode(&head, 2);
    struct node *link3 = addNode(&head, 4);
    struct node *link4 = addNode(&head, 8);
    struct node *link5 = addNode(&head, 16);
    struct node *link6 = addNode(&head, 32);
    struct node *link7 = addNode(&head, 64);

    printf("%d\n", getNode(head, 32)->data); // 32
    removeNode(&head, 1);
    printf("%d\n", head->data); // 2
    removeNode(&head, 32);
    printf("%d\n", getNode(head, 16)->next->data); // 64

    removeList(&head);
}

