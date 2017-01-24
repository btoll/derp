#include <stdio.h>
#include <stdlib.h>

static struct node *head;

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct node *addNode(int data) {
    struct node *newNode = malloc(sizeof(struct node));

    if (!head) {
        head = newNode;
        head->data = data;
        head->next = NULL;
        head->prev = NULL;
    } else {
        struct node *curr = head;

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

struct node *getNode(int data) {
    struct node *copy = head;
    struct node *found;

    while (copy->data) {
        if (copy->data == data) {
            found = copy;
            break;
        }

        copy = copy->next;
    }

    return found;
}

void removeNode(int data) {
    struct node *copy = head;
    struct node *found;
    struct node *prev;

    while (copy->data) {
        if (copy->data == data) {
            found = copy;
            break;
        }

        prev = copy;
        copy = copy->next;
    }

    if (found) {
        // If the node to be removed is the HEAD.
        if (copy == head) {
            head = copy->next;
        }
        // If the node to be removed is the TAIL.
        else if (copy->next == NULL) {
            prev->next = NULL;
        } else {
            prev->next = found->next;
        }

        free(found);
    }
}

void main(void) {
    struct node *link = addNode(1);
    struct node *link2 = addNode(2);
    struct node *link3 = addNode(4);
    struct node *link4 = addNode(8);
    struct node *link5 = addNode(16);
    struct node *link6 = addNode(32);
    struct node *link7 = addNode(64);

    printf("%d\n", getNode(8)->prev->data);
//     printf("%d\n", getNode(4)->prev->next->data);
//     printf("%d\n", getNode(32)->data);
//     removeNode(1);
//     printf("%d\n", head->data);
//     removeNode(32);
//     printf("%d\n", getNode(16)->next->data);
}

