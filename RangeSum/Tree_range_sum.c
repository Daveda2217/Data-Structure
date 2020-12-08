// a ~ b 사이의 sum
int range_sum(BSTNode *root, int a, int b)
{
    if (root == NULL)
        return 0;

    int ret = (root->key >= a && root->key <= b) ? dia[root->key] : 0;

    return ret + range_sum(root->left_child, a, b) + range_sum(root->right_child, a, b);
}