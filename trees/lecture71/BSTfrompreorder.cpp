class Solution {
public:
    TreeNode* help(vector<int>&preorder, int &i, int bound){
        if(i==preorder.size() || preorder[i]>bound){
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[i++]);
        root->left = help(preorder, i, root->val);
        root->right = help(preorder, i, bound); // important step is that in right we use previous bound
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return help(preorder, i, INT_MAX);
    }
};