  ListNode *detectCycle(ListNode *head) {
        if(!head || !(head->next))return NULL;
        ListNode*slow = head, *fast = head, *entry = head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast){
                while(entry!=slow){
                    entry = entry->next;
                    slow = slow->next;
                }
                return slow;
            }
        } 
        return NULL;
    }