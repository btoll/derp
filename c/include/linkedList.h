typedef struct {
    struct node *next;
    struct node *prev;
    struct node *child;
    int data;
} node;

typedef struct {
    struct node *head;
    struct node *tail;
} list;

struct node *addNode(struct list **list, int data);
struct node *insertAfter(struct node **head, struct node **tail, struct node *elem, int data);
void printNodes(struct list *list);
struct list *makeList(void);
// int removeHead(struct node **head, struct node **tail);
int removeNode(struct node **head, struct node **tail, struct node *toRemove);
void removeList(struct node **head, struct node **tail);

