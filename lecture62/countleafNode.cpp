void inorder(BinaryTreeNode<int> *root, int &count)//passing count by reference
{
    // base case
    if (root == NULL)
        return;
     //checking leaf node
    inorder(root->left,count);
    if(root->left==NULL && root->right==NULL){
        count++;
    }
    inorder(root->right, count);
}
int noOfLeafNodes(BinaryTreeNode<int> *root){
    int count=0;
    inorder(root, count);
    return count;
}