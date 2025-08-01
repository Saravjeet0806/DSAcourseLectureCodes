class Solution {
public:
    TreeNode* parentMap(TreeNode* root,
                        unordered_map<TreeNode*, TreeNode*>& mpp, int start) {
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* res = NULL;
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node->val == start) {
                res = node;    
            }
            if (node->left) {
                mpp[node->left] = node;
                q.push(node->left);
            }
            if (node->right) {
                mpp[node->right] = node;
                q.push(node->right);
            }
        }
        return res;
    }
    int help(unordered_map<TreeNode*, TreeNode*>& mpp, TreeNode* target) {
        queue<TreeNode*> q;
        q.push(target);
        map<TreeNode*, int> vis;
        vis[target] = 1;
        int maxi = 0;
        while (!q.empty()) {
            int sz = q.size();
            int fl = 0;
            for (int i = 0; i < sz; i++) {
                auto node = q.front();
                q.pop();
                if (node->left && !vis[node->left]) {
                    fl = 1;
                    q.push(node->left);
                    vis[node->left] = 1;
                }
                if (node->right && !vis[node->right]) {
                    fl = 1;
                    q.push(node->right);
                    vis[node->right] = 1;
                }
                if (mpp[node] && !vis[mpp[node]]) {
                    fl = 1;
                    q.push(mpp[node]);
                    vis[mpp[node]] = 1;
                }
            }
            if (fl)
                maxi++; // if flag is 1 increase the time/maxi
        }
        return maxi;
    }

    int amountOfTime(TreeNode* root, int start) {
        if (root == NULL)
            return 0;
        unordered_map<TreeNode*, TreeNode*> mpp;
        TreeNode* target = parentMap(
            root, mpp, start); // used to find parent mapping and start node
        int maxtime = help(mpp, target);
        return maxtime;
    }
};