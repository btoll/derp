// This implementation has both HEAD and TAIL pointers.
// As a fun exercise, the HEAD and TAIL are passed to the functions as pointers to the pointers.
//
#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *next;
    int data;
};

struct node *addNode(struct node **head, struct node **tail, int data) {
    struct node *newNode;

    if (!(newNode = malloc(sizeof(struct node)))) {
        fprintf(stderr, "Could not allocate memory for new node!");
        exit(1);
    }

    if (*head == NULL) {
        newNode->data = data;
        newNode->next = NULL;
        *head = newNode;
        *tail = newNode;
    } else {
        struct node *curr = *head;

        while (curr->next) {
            curr = curr->next;
        }

        curr->next = newNode;
        newNode->data = data;
        newNode->next = NULL;

        if (newNode->next == NULL) {
            *tail = newNode;
        }
    }

    return newNode;
}

struct node *insertAfter(struct node **head, struct node **tail, struct node *elem, int data) {
    struct node *newNode, *curPos = *head;

    if (!(newNode = malloc(sizeof(struct node)))) {
        fprintf(stderr, "Could not allocate memory for new node!");
        exit(1);
    }

    if (elem == NULL) {
        if (*head == NULL) {
            newNode->data = data;
            newNode->next = NULL;

            *head = newNode;
            *tail = newNode;

            return newNode;
        } else {
            newNode->data = data;
            newNode->next = *head;

            *head = newNode;

            if (*tail == NULL) {
                *tail = newNode;
            }

            return newNode;
        }
    }

    while (curPos) {
        if (curPos == elem) {
            newNode->data = data;
            newNode->next = curPos->next;
            curPos->next = newNode;

            // Update TAIL pointer if the new node is the last.
            if (newNode->next == NULL) {
                *tail = newNode;
            }

            return newNode;
        }

        curPos = curPos->next;
    }

    // Insert position not found, free newNode memory!
    free(newNode);

    return NULL;
}

int removeHead(struct node **head, struct node **tail) {
    struct node *newHead;

    if (head && *head) {
        newHead = (*head)->next;
        free(*head);
        *head = newHead;

        if (*head == NULL) {
            *tail = NULL;
        }
    }
}

int removeNode(struct node **head, struct node **tail, struct node *toRemove) {
    struct node *curPos = *head;

    if (toRemove == NULL) {
        return 1;
    }

    if (*head == toRemove) {
        *head = toRemove->next;
        free(toRemove);

        // Special case for one element list.
        if (*head == NULL) {
            *tail == NULL;
        }

        return 0;
    }

    while (curPos) {
        if (curPos->next == toRemove) {
            curPos->next = toRemove->next;
            free(toRemove);

            // Update TAIL pointer when deleting the last element.
            if (curPos->next == NULL) {
                *tail = curPos;
            }

            return 0;
        }

        curPos = curPos->next;
    }

    return 1;
}

void removeList(struct node **head, struct node **tail) {
    struct node *toDelete = *head;

    while (toDelete) {
        struct node *next = toDelete->next;
        free(toDelete);
        toDelete = next;
    }

    *head = NULL;
    *tail = NULL;
}

void main(void) {
    struct node *head = NULL;
    struct node *tail = NULL;

    struct node *link1= addNode(&head, &tail, 1);
    struct node *link2 = addNode(&head, &tail, 2);
//     struct node *link3 = addNode(&head, &tail, 4);
//     struct node *link4 = addNode(&head, &tail, 8);
//     struct node *link5 = addNode(&head, &tail, 16);
//     struct node *link6 = addNode(&head, &tail, 32);
//     struct node *link7 = addNode(&head, &tail, 64);

    printf("%d\n", head->data);
    printf("%d\n", tail->data);
    removeHead(&head, &tail);
    printf("%d\n", head->data);
    printf("%d\n", tail->data);
    removeHead(&head, &tail);
    printf("%d\n", head);
    printf("%d\n", tail);
}

