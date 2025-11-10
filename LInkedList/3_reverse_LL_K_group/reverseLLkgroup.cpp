class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        //base case
     if(head==NULL){
         return NULL;
     }
     ListNode* next=NULL;
     ListNode* curr=head;
     ListNode* prev=NULL;
     int count=0;

     //iterative algo
     while (curr != NULL && count< k) {
            curr = curr->next;
            count++;
        }
        if (count< k) {
            return head;
        }

        curr = head;
        count = 0;
     while(curr!=NULL&&count<k){
         next=curr->next;
         curr->next=prev;
         prev=curr;
         curr=next;
         count++;
     }
     //step 2 recursive call
     if(next!=NULL){
         head->next=reverseKGroup(next,k);
     }
     //step3 return head of reversed LL reverse prev;
     return prev;
    }
};