https://www.geeksforgeeks.org/problems/children-sum-parent/1
class Solution {
  public:
    int helper(Node* root){
        if(root==NULL) return 0;
        if(root->left==NULL && root->right==NULL) return root->data;
        
        int left= helper(root->left);
        if(left==-1) return -1;
        
        int right=helper(root->right);
        if(right==-1) return -1;
        
        if(root->data ==(left+right)){
            return (root->data);
        }
        return -1;
    }
    int isSumProperty(Node *root) {
     
        int value = helper(root);
        return (value == -1) ? 0 : 1;
    }
};