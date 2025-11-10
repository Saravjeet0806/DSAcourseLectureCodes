
Node *removeDuplicates(Node *head)
{
    unordered_map<int , bool> visited;
    Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL)
    {
        if(visited[temp->data] != true)
        {
            visited[temp->data] = true;
            prev = temp;
           temp = temp->next;
        }
        else
        {
            prev->next = temp->next;
            temp = prev->next;
        }
    }
    return head;
}