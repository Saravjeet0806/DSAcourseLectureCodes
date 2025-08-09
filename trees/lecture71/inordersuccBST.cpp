https://www.geeksforgeeks.org/problems/inorder-successor-in-bst/1
class Solution {
  public:
   int inOrderSuccessor(Node *root, Node *x) {
    Node* succ = NULL;

    while (root != NULL) {
        if (x->data >= root->data) {
            root = root->right;
        } else {
            succ = root;
            root = root->left;
        }
    }

    if (succ != NULL)
        return succ->data;
    else
        return -1; 
}

};