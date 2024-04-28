node *findMid(node* head){
    node*slow=head;
    node*fast=head->next;

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;

    }
    return slow;
}

node* merge(node* left, node* right){
    if(left==NULL)
    return right;
    if(right==NULL)
    return left;

    node*ans=new node(-1);   //creating dummy node
    node* temp=ans;

    //merge two sorted LL
    while(left!=NULL && right!=NULL){
        if(left->data<right->data){
            temp->next=left;
            temp=left;
            left=left->next;
        }
        else{
            temp->next=right;
            temp=right;
            right=right->next;
        }
    }
    while(left!=NULL){  //handling cases
        temp->next=left;
            temp=left;
            left=left->next;

    }
    while(right!=NULL){//handling cases
        temp->next=right;
            temp=right;
            right=right->next;
    }

    ans=ans->next;  //dummy node removed
    return ans;
}
node* mergeSort(node *head) {
   if(head==NULL || head ->next ==NULL)
   return head;

   //break 2 LL
   node * mid=findMid(head);
   node* left=head;
   node* right=mid->next;
   mid->next=NULL;

   //sort bothh halves
   left=mergeSort(left);
   right=mergeSort(right);

   //merge both halves
   node*result=merge(left, right);
   return result;

}
