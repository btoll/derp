#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *next;
    struct node *prev;
    struct node *child;
    int data;
};

struct list {
    struct node *head;
    struct node *tail;
};

struct node *addNode(struct list **list, int data) {
    struct node *newNode;

    if (!(newNode = malloc(sizeof(struct node)))) {
        printf("Could not allocate memory for new node!");
        exit(1);
    }

    if ((*list)->head == NULL) {
        newNode->data = data;
        newNode->next = NULL;
        newNode->prev = NULL;
        (*list)->head = newNode;
        (*list)->tail = newNode;
    } else {
        struct node *curr = (*list)->head;

        while (curr->next) {
            curr = curr->next;
        }

        curr->next = newNode;
        newNode->data = data;
        newNode->next = NULL;
        newNode->prev = curr;

        if (newNode->next == NULL) {
            (*list)->tail = newNode;
        }
    }

    return newNode;
}

/*
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
            struct node *newHead;

            newHead = link->next;
            newHead->prev = NULL;
            *head = newHead;
        }
        // If the node to be removed is the TAIL.
        else if (link->next == NULL) {
            prev->next = NULL;
        } else {
            prev->next = link->next;
            link->next->prev = prev;
        }

        free(link);
    }
}
*/

/*
void removeList(struct node **head) {
    struct node *toDelete = *head;

    while (toDelete) {
        struct node *next = toDelete->next;
        free(toDelete);
        toDelete = next;
    }
}
*/

struct list *makeList() {
    struct list *newList;

    if (!(newList = malloc(sizeof(struct node)))) {
        printf("Could not allocate memory for new node!");
        exit(1);
    }

    return newList;
}

