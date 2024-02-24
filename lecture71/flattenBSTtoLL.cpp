void inorder (TreeNode<int>* root,vector <int> &in ){
    if(root==NULL)
    return ;
    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

TreeNode<int>* flatten(TreeNode<int>* root)
{
   vector <int> inorderVal;
    inorder(root, inorderVal);
    int n= inorderVal.size();
   //1st step
    TreeNode<int>* newRoot= new TreeNode<int>(inorderVal[0]);
    TreeNode<int>* curr=newRoot;
   // 2nd step
    for(int i=1; i<n; i++){
       TreeNode<int>*temp= new TreeNode<int>(inorderVal[i]);
       curr->left=NULL;
       curr->right=temp;
       curr=temp; 
    }
    //3rd step
    curr->left=NULL;
    curr->right=NULL;

    return newRoot;
}