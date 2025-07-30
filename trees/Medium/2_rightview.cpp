class Solution {
public:
    void helper(vector<int>&ans, TreeNode* root,int level){
        if(root==NULL) return;

        if(level==ans.size()){
            ans.push_back(root->val);
        }
        helper(ans, root->right, level+1);
        helper(ans, root->left, level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        helper(ans, root, 0);
        return ans;
    }
};

