#include <iostream>
#include <map>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "memory freed for node with data" << value << endl;
    }
};
void insertNode(Node *&tail, int element, int d)
{
    if (tail == NULL)
    {
        // empty list
        Node *newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode;
    }
    else
    {
        // non-empty list assuming that the element is present in last
        Node *curr = tail;
        while (curr->data != element)
        {
            curr = curr->next;
        }
        // element found curr is representing element wala node
        Node *temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}
void print(Node *tail)
{
    Node *temp = tail;
    if (tail == NULL)
    {
        cout << "List is empty" << endl;
    }
    do
    {
        cout << tail->data << " ";
        tail = tail->next;
    } while (tail != temp);
    cout << endl;
}
void deleteNode(Node *&tail, int value)
{
    // emptylist
    if (tail == NULL)
    {
        cout << "list is empty, please check again";
        return;
    }
    else
    {
        // non empty
        // assuming that "value" is present in the linkedlist
        Node *prev = tail;
        Node *curr = prev->next;

        while (curr->data != value)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        // one node linkedlist
        if (curr == prev)
        {
            tail = NULL;
        }
        else if (tail == curr)
        {
            tail = prev;
        }
        curr->next = NULL;
        delete curr;
    }
}
bool isCircularList(Node* head){
    if(head==NULL){
        return false;
    }
    Node *temp=head->next;
    while(temp!=NULL && temp!=head){
        temp=temp->next;
    }
    if(temp==head){
        return true;
    }
    return false;
}
//for checking large LL so that there is no time limit exceeded error
// bool isCircularList(Node* head){

//     if(head== NULL){
//         return true;
//     }
//     if(head->next==NULL ){
//         return false;
//     }
//      Node* temp = head->next;
//     while(temp!= NULL ){
//         if(temp->data == head->data){
//             return true;
//         }
//         else if(temp->data == NULL) 
//         return false;
//         temp->data = NULL;
//         temp = temp->next;
//     }
//     return false;
// }
bool detectLoop(Node * head){
    if(head==NULL){
        return false;
    }
    map< Node*, bool> visited;
    Node * temp=head;
    while(temp!=NULL){
        //cycle is present
        if(visited[temp]==true){
            return true;
        }
        visited[temp]=true;
        temp=temp->next;
    }
    return false;
}
int main()
{
    Node *tail = NULL;
    insertNode(tail, 5, 3); // insertion in empty node
    print(tail);
    insertNode(tail, 3, 5);
    print(tail);
    insertNode(tail, 5, 7);
    print(tail);
    insertNode(tail, 7, 9);
    print(tail);
    insertNode(tail, 5, 6);
    print(tail);
    deleteNode(tail, 3);
    print(tail);
    if(isCircularList(tail)){
        cout<<"linked list is circular"<<endl;
    }
    else
    cout<<"linked list is non circular"<<endl;
      if(detectLoop(tail)){
    cout<<"loop is detected"<<endl;
   }
   else
   cout<<"LOOP is not detected"<<endl;

    return 0;
}