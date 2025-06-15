 // question link - https://www.geeksforgeeks.org/problems/is-binary-tree-heap/1

class Solution {
    private:
   int countNodes(struct Node * root){
       if(root==NULL)
       return 0;
       int ans= 1+ countNodes(root->left)+ countNodes(root->right);
       return ans;
   } 
   bool isCBT(struct Node* root, int index, int cnt){
       if(root==NULL) return true;
       if(index>=cnt)
       return false;
       
       else{
           bool left=isCBT(root->left, 2*index+1, cnt);
            bool right=isCBT(root->right, 2*index+2, cnt);
            return (left && right);
       }
   }
   bool isMaxOrder(struct Node* root){
       if(root->left == NULL && root ->right == NULL)
       return true;
       if(root->right==NULL){
           return (root->data>root->left->data);
       }
       else{
           bool left=isMaxOrder(root->left);
           bool right=isMaxOrder(root->right);
           return(left && right && (root->data> root->left->data && root->data > root->right->data));
       }
   }
  public: 
    bool isHeap(struct Node* tree) {
        int index =0;
        int totalCount= countNodes(tree);
       if(isCBT(tree, index, totalCount) && isMaxOrder(tree)){
           return true;
       }
       else
       return false;
    }
};

//code studio solution

//  int countNodes(BinaryTreeNode<int>* root){
//        if(root==NULL)
//        return 0;
//        int ans= 1+ countNodes(root->left)+ countNodes(root->right);
//        return ans;
//    } 
//    bool isCBT(BinaryTreeNode<int>* root, int index, int cnt){
//        if(root==NULL) return true;
//        if(index>=cnt)
//        return false;
       
//        else{
//            bool left=isCBT(root->left, 2*index+1, cnt);
//             bool right=isCBT(root->right, 2*index+2, cnt);
//             return (left && right);
//        }
//    }
//    bool isMaxOrder(BinaryTreeNode<int>* root){
//          if(root==NULL) return true;
//     bool left = isMaxOrder(root->left);
//     bool right = isMaxOrder(root->right);
//     if(root->left!=NULL && root->data < root->left->data) return false;
//     if(root->right!=NULL && root->data < root->right->data) return false;

//     return ( left&&right );
//    }
// bool isBinaryHeapTree(BinaryTreeNode<int>* root) 
// {
//     if(isCBT(root,0,countNodes(root)) && isMaxOrder(root)) 
//      return true;
//     else
//      return false;
//     return false;
// }