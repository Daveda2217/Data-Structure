#define MAXSIZE 100

typedef int Data;

typedef enum
{
    false,
    true
} bool;

typedef struct
{
    Data top;
    Data items[MAXSIZE];
} Stack;

void init(Stack *s)
{
    s->top = -1;
}

bool empty(Stack *s)
{
    return s->top == -1;
}

bool full(Stack *s)
{
    return s->top == MAXSIZE - 1;
    // Because of Zero Indexing
}

void push(Stack *s, Data data)
{
    if (!full(s))
        s->items[++(s->top)] = data;
    // You must use ++(index)
    // Because initial top is -1
}

Data peek(Stack *s)
{
    if (!empty(s))
        return (s->items[s->top]);
}

void pop(Stack *s)
{
    if (!empty(s))
        --(s->top);
}