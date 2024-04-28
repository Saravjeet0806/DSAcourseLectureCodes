
TreeNode *LCAinaBST(TreeNode *root, TreeNode *P, TreeNode *Q)
{
    while (root != NULL)
    {
        if (root->data < P->data && root->data < Q->data)
            root = root->right;

        else if (root->data > P->data && root->data > Q->data)
            root = root->left;

        else
            return root;
    }
}
TreeNode *LCAinaBST(TreeNode *root, TreeNode *P, TreeNode *Q)
{
    while (root != NULL)
    {
        if (root->data < P->data && root->data < Q->data)
            root = root->right;

        else if (root->data > P->data && root->data > Q->data)
            root = root->left;

        else
            return root;
    }
}