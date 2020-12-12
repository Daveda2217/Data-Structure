#define MAX_QUEUE 100
// 0~99까지 100개

typedef int Data;

typedef enum
{
    false,
    true
} bool;

typedef struct
{
    int front, rear;
    Data items[MAX_QUEUE];
} Queue;

void InitQueue(Queue *pq)
{
    pq->front = pq->rear = 0;
}

bool IsFull(Queue *pq)
{
    return pq->front == (pq->rear + 1) % MAX_QUEUE;
}

bool IsEmpty(Queue *pq)
{
    return pq->front == pq->rear;
}

Data Peek(Queue *pq)
{
    if (IsEmpty(pq))
        exit(1);
    return pq->items[pq->front];
}

void EnQuene(Queue *pq, Data item)
{
    if (IsFull(pq))
        exit(1);
    pq->items[pq->rear];
    pq->rear = (pq->rear + 1) % MAX_QUEUE;
}

void DeQueue(Queue *pq)
{
    if (IsEmpty(pq))
        exit(1);
    pq->front = (pq->front + 1) % MAX_QUEUE;
}
