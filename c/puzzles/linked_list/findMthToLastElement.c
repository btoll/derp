#include "../../include/linkedList.c"

struct node *findMth(struct node *head, int m) {
    struct node *curPos = head, *mthElem = head;
    int len = -1;

    if (!head) {
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
        fprintf(stderr, "Out of bounds");
        exit(1);
    }

    return mthElem;
}

void main(void) {
    struct list *list = makeList();

    struct node *link1= addNode(&list, 1);
    struct node *link2 = addNode(&list, 2);
    struct node *link3 = addNode(&list, 4);
    struct node *link4 = addNode(&list, 8);
    struct node *link5 = addNode(&list, 16);
    struct node *link6 = addNode(&list, 32);
    struct node *link7 = addNode(&list, 64);
    struct node *link8 = addNode(&list, 128);
    struct node *link9 = addNode(&list, 256);
    struct node *link10 = addNode(&list, 512);
    struct node *link11 = addNode(&list, 1024);
    struct node *link12 = addNode(&list, 2048);

    struct node *mth = findMth(list->head, 1);

    if (mth) {
        printf("%d\n", mth->data);
    } else {
        printf("HEAD is NULL\n");
    }
}

