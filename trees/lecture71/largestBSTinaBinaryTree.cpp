https://www.geeksforgeeks.org/dsa/largest-bst-binary-tree-set-2/
class BSTInfo {
  public:
    int min;
    int max;
    int mxSz;

    BSTInfo(int mn, int mx, int sz) {
        min = mn;
        max = mx;
        mxSz = sz;
    }
};

class Solution {
  public:
  BSTInfo largestBSTBT(Node *root) {
    if (!root)
        return BSTInfo(INT_MAX, INT_MIN, 0);

    BSTInfo left = largestBSTBT(root->left);
    BSTInfo right = largestBSTBT(root->right);

    // Check if the current subtree is a BST
    if (left.max < root->data && right.min > root->data) {
        return BSTInfo(min(left.min, root->data), 
                       max(right.max, root->data), 1 + left.mxSz + right.mxSz);
    }

    return BSTInfo(INT_MIN, INT_MAX, max(left.mxSz, right.mxSz));
}
    int largestBst(Node *root) {
        return largestBSTBT(root).mxSz;
    }
};