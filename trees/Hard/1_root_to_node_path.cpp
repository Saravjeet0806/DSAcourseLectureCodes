https://www.geeksforgeeks.org/problems/root-to-leaf-paths/1

class Solution {
    void helper(vector<vector<int>>&ans, Node*root, vector<int>&ds){
        if (root == NULL) return;
        ds.push_back(root->data);

        if (root->left == NULL && root->right == NULL) {
            // Reached a leaf node
            ans.push_back(ds);
        } else {
            helper(ans, root->left, ds);
            helper(ans, root->right, ds);
        }

        // Backtrack
        ds.pop_back();
    }
  public:
    vector<vector<int>> Paths(Node* root) {
        vector<int>ds;
        vector<vector<int>>ans;
        helper(ans, root, ds);
        return ans;
    }
};