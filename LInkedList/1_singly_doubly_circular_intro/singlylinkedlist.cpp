#include <iostream>
#include <map>
using namespace std;
// dont forget to handle the case of empty linked list
class Node
{
public:
    int data;
    Node *next;

    //constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    //destructor
    ~Node(){
        int value = this ->data;
        //memory freeing
        if(this->next != NULL){
            delete next;
            this->next=NULL;
        }
        cout<<"memory is free for node with data"<<value<<endl;
    }
};
void InsertAtHead(Node *&head, int d)
{ // reference liya of head
    // new node create
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}
void InsertAtTail(Node *&tail, int d)
{
    // new node create
    Node *temp = new Node(d);
    tail->next = temp;
    tail = tail->next;
}

void print(Node *&head)
{
    if(head==NULL){
        cout<<"linked list is empty"<<endl;
        return;
    }
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void InsertAtPosition(Node *&head, Node *&tail, int position, int d)
{
    if (position == 1)
    { // to insert at head  coz we need previous element
        InsertAtHead(head, d);
        return;
    }
    Node *temp = head;
    int cnt = 1;

    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }
    // inserting at last
    if (temp->next == NULL)
    {
        InsertAtTail(tail, d);
        return;
    }

    // creating a node for d
    Node *nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

void deleteNode(int position, Node * &head){
    //deletion at starting
    if(position==1){
        Node*temp=head;
        head =head->next;
        //memory free of start node
        temp->next = NULL; //node jisko delete karna hai usko null se point karadiya
        delete temp;     
    }
    else{
    //deleting any middle node or last node
    Node*curr=head;   //curr == current
    Node*prev = NULL;

    int cnt=1;
    while(cnt<position){
        prev = curr;
        curr=curr->next;  // current ko aage badhaya
        cnt++;
    }
    prev ->next = curr->next; 
    curr->next= NULL; // node jisko delete karna hai usko null se point kardiya
    delete curr;
    }
    
}
bool isCircularList(Node* head) {
    //empty list
    if(head == NULL) {
        return true;
    }

    Node* temp = head -> next;
    while(temp != NULL && temp != head ) {
        temp = temp -> next;
    }

    if(temp == head ) {
        return true;
    }

    return false;
}
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
Node* floydDetectLoop(Node* head){
    if(head==NULL){
        return NULL;
    }
    Node * slow=head;
    Node * fast=head;
    while(slow!=NULL && fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast = fast->next;
        }
        slow=slow->next;
        if(slow==fast){
            cout<<"cycle present at"<<slow->data<<endl;
            return slow;
        }
    }
    return NULL;
}
Node* getStartingNode(Node* head){
    if(head==NULL){
        return NULL;
    }
    Node* intersection = floydDetectLoop(head);
    Node* slow=head;
    while(slow!=intersection){
        slow=slow->next;
        intersection=intersection->next;
    }
    return slow;
}
void removeLoop(Node* head) {

    if( head == NULL)
        return;

    Node* startOfLoop = getStartingNode(head);
    Node* temp = startOfLoop;

    while(temp -> next != startOfLoop) {
        temp = temp -> next;
    } 

    temp -> next = NULL;

}

int main()
{

    // creating a new node
    Node *node1 = new Node(10);
    cout << node1->data << endl;
    cout << node1->next << endl;

    // head pointed to node1
    Node *head = node1;
    Node *tail = node1;
    print(head);
    // For inserting at head
    // InsertAtHead(head, 12); // inserting 12 at head
    // print(head);
    // InsertAtHead(head, 15); // inserting 15 at head
    // print(head);
    // output = 15 12 10

    // for inserting at tail
    // InsertAtTail(tail, 10); // same node me head tail se hoga
    // print(head);
    // InsertAtTail(tail, 20);
    // print(head);
    // InsertAtTail(tail, 30);
    // print(head);
    // //output = 10 20 30

    // for inserting at any position

    InsertAtTail(tail, 12);
    // print(head);
    InsertAtTail(tail, 15);
    // print(head);

    InsertAtPosition(head,tail, 3, 22); // inserting 22 at 3rd position
    print(head);
    InsertAtPosition(head, tail, 1, 33);
    // print(head);
    InsertAtPosition(head, tail, 6, 104);
    print(head);
    // deleteNode(4,head);
    // print(head);
    // cout<<"head"<<head->data<<endl;
    // cout<<"tail"<<tail->data<<endl;
    // deleteNode(5,head);
    // print(head);
    // cout<<"head"<<head->data<<endl;
    // cout<<"tail"<<tail->data<<endl;  //pointing to garbage value now
    //   if(isCircularList(head)){
    //     cout<<"linked list is circular"<<endl;
    // }
    // else{
    // cout<<"linked list is non circular"<<endl;
    // }
    tail->next=head->next;
    
   if(detectLoop(head)){
    cout<<"loop is detected"<<endl;
   }
   else
   cout<<"LOOP is not detected"<<endl;
    if(floydDetectLoop(head)!=NULL){
    cout<<"loop is detected"<<endl;
   }
   else
   cout<<"LOOP is not detected"<<endl;

   Node* Loop= getStartingNode(head);
   cout<<"Loop is present at"<<Loop->data<<endl;

 removeLoop(head);
   print(head);
    
    return 0;
}


