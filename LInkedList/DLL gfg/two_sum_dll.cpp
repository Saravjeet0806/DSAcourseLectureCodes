https://www.geeksforgeeks.org/problems/find-pairs-with-given-sum-in-doubly-linked-list/1

class Solution {
  public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        vector<pair<int,int>> ans;

        // find the tail of DLL
        Node* left = head;
        Node* right = head;
        while (right->next) {
            right = right->next;
        }

        // two-pointer traversal
        while (left && right && left != right && right->next != left) {
            int sum = left->data + right->data;

            if (sum == target) {
                ans.push_back({left->data, right->data});
                left = left->next;
                right = right->prev;
            }
            else if (sum < target) {
                left = left->next;
            }
            else {
                right = right->prev;
            }
        }

        return ans;
    }
};