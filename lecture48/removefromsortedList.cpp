
Node * removeDuplicates(Node *head)
{
    if(head==NULL)
    return NULL ; //empty list

    //non empty list
    Node* curr= head;
    while(curr!=NULL){

        if((curr->next!=NULL) && curr->data==curr->next->data){
          Node * next_next = curr->next->next;  //taken a pointer
          Node* nodeToDelete=curr->next;
          delete(nodeToDelete);
          curr->next=next_next;     
        } 
        else   // not equal
        {
            curr=curr->next;
        }
    }
    return head;
}
