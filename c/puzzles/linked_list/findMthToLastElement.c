#include "../../include/linkedList.c"

struct node *findMth(struct node **head, int m) {
    struct node *curPos = *head, *mthElem = *head;
    int len = -1;

    if (!*head) {
        return NULL;
    }

    while (curPos) {
        if (len >= m) {
            mthElem = mthElem->next;
        }

        len++;
        curPos = curPos->next;
    }

    if (m > len) {
        printf("Out of bounds");
        exit(1);
    }

    return mthElem;
}

void main(void) {
    struct node *head = NULL;
    struct node *tail = NULL;

    struct node *link1= addNode(&head, &tail, 1);
    struct node *link2 = addNode(&head, &tail, 2);
    struct node *link3 = addNode(&head, &tail, 4);
    struct node *link4 = addNode(&head, &tail, 8);
    struct node *link5 = addNode(&head, &tail, 16);
    struct node *link6 = addNode(&head, &tail, 32);
    struct node *link7 = addNode(&head, &tail, 64);
    struct node *link8 = addNode(&head, &tail, 128);
    struct node *link9 = addNode(&head, &tail, 256);
    struct node *link10 = addNode(&head, &tail, 512);
    struct node *link11 = addNode(&head, &tail, 1024);
    struct node *link12 = addNode(&head, &tail, 2048);

    struct node *mth = findMth(&head, 8);

    if (mth) {
        printf("%d\n", mth->data);
    } else {
        printf("HEAD is NULL\n");
    }
}

