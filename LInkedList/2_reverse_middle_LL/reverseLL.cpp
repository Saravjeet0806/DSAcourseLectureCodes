class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL){ //empty list and one node
            return head;
        }  
       ListNode* prev = NULL;
       ListNode* curr= head;
       ListNode* forward=NULL;

       while(curr!= NULL){
           forward=curr->next;
           curr -> next = prev;
           prev=curr;
           curr=forward;
       }
       return prev;

    }
};