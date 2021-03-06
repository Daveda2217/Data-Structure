#include <stdio.h>
#include <stdlib.h>

typedef enum
{
    false,
    true
} bool;

typedef struct _BSTNode
{
    int key;
    struct _BSTNode *left_child;
    struct _BSTNode *right_child;
} BSTNode;

BSTNode *CreateNode(int key)
{
    BSTNode *node = (BSTNode *)malloc(sizeof(BSTNode));
    node->key = key;
    node->left_child = NULL;
    node->right_child = NULL;

    return node;
}

// initial min & max == INT_MIN & INT_MAX
bool Verify(BSTNode *root, int min, int max)
{
    if (root != NULL)
    {
        if (root->key < min || root->key > max)
            return false;
        else
        {
            return Verify(root->left_child, min, root->key) &&
                   Verify(root->right_child, root->key, max);
        }
    }
    else // empty tree
        return true;
}

BSTNode *search_recursion(BSTNode *root, int key)
{
    if (root == NULL || root->key == key)
        return root;
    else if (root->key > key)
        return search_recursion(root->left_child, key);
    else
        return search_recursion(root->right_child, key);
}

BSTNode *search_iteration(BSTNode *root, int key)
{
    BSTNode *cur = root;

    while (cur != NULL)
    {
        if (cur->key == key)
            break;
        else if (cur->key > key)
            cur = cur->left_child;
        else
            cur = cur->right_child;
    }

    return cur;
}

BSTNode *Insert_recursion(BSTNode *root, int key)
{
    if (root == NULL)
    {
        return CreateNode(key);
    }
    if (root->key > key)
    {
        root->left_child = Insert_recursion(root->left_child, key);
    }
    else
    {
        root->right_child = Insert_recursion(root->right_child, key);
    }
    return root;
}

void Insert_iteration(BSTNode *root, int key)
{
    BSTNode *cur = root;
    while (cur != NULL)
    {
        if (cur->key == key)
            exit(1);
        else if (cur->key > key)
        {
            if (cur->left_child == NULL)
            {
                CreateLeftSubtree(cur, key);
                break;
            }
            else
                cur = cur->left_child;
        }
        else
        {
            if (cur->right_child == NULL)
            {
                CreateRightSubtree(cur, key);
                break;
            }
            else
                cur = cur->right_child;
        }
    }
}

/*
Delete Function
1) no children
2) one child
3) two child
- the biggest one in the left subtree
- the smallest one in the right subtree
*/
void Remove(BSTNode *root, int key)
{
    BSTNode *cur = root, *parent = NULL;

    // find key while cur != NULL
    while (cur != NULL && cur->key != key)
    {
        parent = cur;
        if (cur->key > key)
            cur = cur->left_child;
        else
            cur = cur->right_child;
    }

    // case 1
    if (cur->left_child == NULL && cur->right_child == NULL)
    {
        if (parent != NULL)
        {
            if (parent->left_child == cur)
                parent->left_child = NULL;
            else
                parent->right_child = NULL;
        }
        else
            cur = NULL; // cur is root
    }
    else if (cur->left_child == NULL || cur->right_child == NULL)
    { // case 2
        BSTNode *child;
        if (cur->left_child != NULL)
            child = cur->left_child;
        else
            child = cur->right_child;

        if (parent != NULL)
        {
            if (parent->left_child == cur)
                parent->left_child = child;
            else
                parent->right_child = child;
        }
    }
    else
    { // case 3
        BSTNode *succ_parent = cur, *succ = cur->right_child;
        while (succ->left_child != NULL)
        {
            succ_parent = succ;
            succ = succ->left_child;
        }

        if (succ_parent->right_child == succ)
        {
            succ_parent->right_child = succ->right_child;
        }
        else
            succ_parent->left_child = succ->right_child;

        cur->key = succ->key;
        cur = succ;
    }
    free(cur);
}

void free_tree(BSTNode *root)
{
    if (root == NULL)
        return;
    if (root->left_child == NULL && root->right_child == NULL)
        free(root);
    else
    {
        if (root->left_child != NULL)
            free_tree(root->left_child);
        if (root->right_child != NULL)
            free_tree(root->right_child);
    }
}
