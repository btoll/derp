typedef struct {
    struct frame *top;
    unsigned size;
} stack;

typedef struct {
    struct frame *next;
    struct node *node;
} frame;

struct stack *initStack(void);
void push(struct stack **stack, struct node *node);
struct node *pop(struct stack **stack);

