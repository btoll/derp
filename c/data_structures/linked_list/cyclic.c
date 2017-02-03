#include "../../include/linkedList.c"

int isCyclic(struct list *list) {
    struct node *slow = list->head;
    struct node *fast = list->head->next;

    while (1) {
        if (!fast || !fast->next)
            return 0;

        if (fast == slow || fast->next == slow)
            return 1;

        slow = slow->next;
        fast = fast->next->next;
    }
}

int main(void) {
    struct list *list = makeList();
    struct node *node;

    addNode(&list, 0);
    addNode(&list, 1);
    addNode(&list, 2);
    addNode(&list, 3);
    addNode(&list, 4);
    addNode(&list, 5);
    addNode(&list, 6);
    node = addNode(&list, 7);
    addNode(&list, 8);
    addNode(&list, 9);
    addNode(&list, 10);
    addNode(&list, 11);
    addNode(&list, 12);
    addNode(&list, 13);
    addNode(&list, 14);

    // Create a cyclic list.
    list->tail->next = node;

    if (isCyclic(list))
        printf("is cyclic");
    else
        printf("is not cyclic");

    return 0;
}

