int findCeil(Node* root, int input) {
    int ceil = -1;
    
    while(root){
        if(root->data==input){
            ceil = root->data;
            return ceil;
        }
        if(root->data<input){
            root=root->right;
        }
        else{
            ceil=root->data;
            root=root->left;
        }
    }
    return ceil;
}

class Solution {

  public:
    int floor(Node* root, int x) {
        int floor = -1;
    
    while(root){
        if(root->data==x){
            floor = root->data;
            return floor;
        }
        if(root->data>x){
            root=root->left;
        }
        else{
            floor=root->data;
            root=root->right;
        }
    }
    return floor;
        
    }
};