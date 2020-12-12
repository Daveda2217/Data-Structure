#include <stdio.h>
#incldue < stdlib.h>

typedef enum
{
    false,
    true
} bool;

typedef int Data;

typedef struct _Node
{
    Data item;
    struct _Node *next;
} Node;

typedef struct
{
    Node *head;
    int len;
} LinkedList;

void InitList(LinkedList *plist)
{
    plist->head = (Node *)malloc(sizeof(Node));
    plist->head->next = NULL;
    plist->len = 0;
}

bool IsEmpty(LinkedList *plist)
{
    return plist->len == 0;
}

void InsertMiddle(LinkedList *plist, int pos, Data item)
{
    Node *cur, *newNode;
    if (pos < 0 || pos > plist->len)
        exit(1);
    newNode = (Node *)malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->item = item;

    cur = plist->head;
    for (int i = 0; i < pos; i++)
    {
        cur = cur->next;
    }

    // 순서 매우 중요!!
    newNode->next = cur->next;
    cur->next = newNode;
    plist->len++;
}

void RemoveMiddle(LinkedList *plist, int pos)
{
    Node *cur, *temp;
    if (IsEmpty(plist) || pos < 0 || pos >= plist->len)
        exit(1);

    cur = plist->head;
    for (int i = 0; i < pos; i++)
    {
        cur = cur->next;
    }
    temp = cur->next;
    cur->next = cur->next->next;
    plist->len--;
    free(temp);
}

Data readItem(LinkedList *plist, int pos)
{
    Node *cur;
    if (IsEmpty(plist) || pos < 0 || pos >= plist->len)
        exit(1);
    cur = plist->head->next;
    for (int i = 0; i < pos; i++)
    {
        cur = cur->next;
    }
    return cur->item;
}

void PrintList(LinkedList *plist)
{
    for (Node *cur = plist->head->next; cur != NULL; cur = cur->next)
    {
        printf("%d\n", cur->item);
    }
}

void ClearList(LinkedList *plist)
{
    while (plist->head->next != NULL)
    {
        RemoveFirst(plist);
    }
    free(plist->head);
}
