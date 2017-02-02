#include "linkedList.c"

struct list *flatten(struct list **to, struct list **from, struct node *link) {
    while(link && link->data) {
        if (link->data)
            addNode(to, link->data);


        if (link->child)
            flatten(to, from, link->child);

        link = link->next;
    }

    return *to;
}

void printNodes(struct list *list) {
    struct node *link = list->head;

    while (link && link->data) {
        printf("node->data: %4d\n", link->data);
        link = link->next;
    }
}

void main(void) {
    // Make lists.
    struct list *list1 = makeList();
    addNode(&list1, 5);
    addNode(&list1, 33);
    addNode(&list1, 17);
    addNode(&list1, 2);
    addNode(&list1, 1);

    struct list *list2 = makeList();
    addNode(&list2, 6);
    addNode(&list2, 25);
    addNode(&list2, 6);

    struct list *list3 = makeList();
    addNode(&list3, 2);
    addNode(&list3, 7);

    struct list *list4 = makeList();
    addNode(&list4, 8);

    struct list *list5 = makeList();
    addNode(&list5, 9);

    struct list *list6 = makeList();
    addNode(&list6, 12);
    addNode(&list6, 5);

    struct list *list7 = makeList();
    addNode(&list7, 7);

    struct list *list8 = makeList();
    addNode(&list8, 21);
    addNode(&list8, 3);

    // Set child nodes.
    list1->head->child = list2->head;
    list1->tail->prev->child = list3->head;

    list2->head->next->child = list4->head;
    list2->tail->child = list5->head;

    list3->head->child = list6->head;
    list5->head->child = list7->head;
    list6->head->child = list8->head;

    // Flatten the lists into one (non-destructive) and print.
    struct list *flattened = makeList();
    printNodes(
        flatten(&flattened, &list1, list1->head)
    );
}

