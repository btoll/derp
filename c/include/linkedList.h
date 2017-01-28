typedef struct {
    struct node *next;
    int data;
} node;

struct node *addNode(struct node **head, struct node **tail, int data);
struct node *insertAfter(struct node **head, struct node **tail, struct node *elem, int data);
int removeHead(struct node **head, struct node **tail);
int removeNode(struct node **head, struct node **tail, struct node *toRemove);
void removeList(struct node **head, struct node **tail);

