#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *next;
    struct node *prev;
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
        newNode->prev = NULL;
        *head = newNode;
    } else {
        struct node *curr = *head;

        while (curr->next != NULL) {
            curr = curr->next;
        }

        curr->next = newNode;
        newNode->data = data;
        newNode->next = NULL;
        newNode->prev = curr;
    }

    return newNode;
}

struct node *getNode(struct node *head, int data) {
    struct node *link = head;
    struct node *found;

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

    printf("%d\n", getNode(head, 8)->prev->data); // 4
    printf("%d\n", getNode(head, 8)->next->next->data); // 32
    printf("%d\n", getNode(head, 64)->prev->prev->prev->data); // 8
    printf("%d\n", getNode(head, 64)->data); // 64

    // Remove TAIL.
    removeNode(&head, 64);
    struct node *tail = getNode(head, 32);
    printf("\n%d\n", tail->prev->data); // 16
    printf("%d\n", tail->next == NULL); // 1 (true)

    // Remove HEAD.
    removeNode(&head, 1);
    printf("\n%d\n", head->data); // 2
    printf("%d\n", getNode(head, 2) == head); // 1 (true)
    printf("%d", head->prev == NULL); // 1 (true)
    printf("\n%d\n", head->next->data); // 4

    removeNode(&head, 8);
    printf("\n%d\n", getNode(head, 4)->next->data); // 16
    printf("%d\n", getNode(head, 16)->prev->data); // 4

    removeList(&head);
}

