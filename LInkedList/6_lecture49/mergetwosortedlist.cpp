lass Solution {
    private:
    ListNode* solve(ListNode* list1, ListNode* list2    ){

    //if only one element is present in the list
    if(list1->next==NULL){
        list1->next=list2;
        return list1;
    }

  ListNode* curr1=list1;
   ListNode* next1=curr1->next;
   ListNode* curr2=list2;
    ListNode* next2=curr2->next;

    while(next1!=NULL && curr2!=NULL ){

        if((curr2->val>=curr1->val) && (curr2->val<=next1->val))            {            
          //add nodes between first LL
            curr1->next=curr2;
            next2=curr2->next;
            curr2->next=next1;
         //update pointers
            curr1=curr2;
            curr2=next2;          
        }
        else{ //when data doesn't lie in range
            //curr1 and next1 ko aage badhao

            curr1=next1;
            next1=next1->next;

            if(next1==NULL){
                curr1->next=curr2;    //second LL puri ki puri first LL me                               chipka di
                return list1;
            }

        }

    }

  return list1;

}
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if(list1==NULL)
    return list2;

    if(list2==NULL)
    return list1;

    if(list1->val<=list2->val){
     return   solve(list1,list2);
    }
    else{
     return   solve(list2,list1);
    }
    }
};