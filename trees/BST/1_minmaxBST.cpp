class Solution {
  public:
    int findMax(Node *root) {
       if(root==NULL)
        {
            
            return INT_MIN;
        }
        int left=findMax(root->left);
        int right=findMax(root->right);
        return max(root->data,max(left,right));
    }

    int findMin(Node *root) {
         if(root==NULL)
            return INT_MAX;
        int left=findMin(root->left);
        int right=findMin(root->right);
        return min(root->data,min(left,right));
    }
};