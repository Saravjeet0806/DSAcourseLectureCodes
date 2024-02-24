#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev; // pointer bana liye of node* type
    Node *next;

    // constructor
    Node(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }
    ~Node(){
        int val = this->data;
        if(next!=NULL){
            delete next;
            next= NULL;
        }
        cout<<"memory freed for node with data "<<val<<endl;
    }
};
void print(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int getLength(Node *head)
{ // function for finding the length of node
    int len = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}
void insertAtHead(Node *&tail, Node *&head, int d)
{
    // empty list handling
    if (head == NULL)
    {
        Node *temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else
    {
        Node *temp = new Node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void insertAttail(Node *&tail, Node *&head, int d)
{
    // empty list handling
    if (tail == NULL)
    {
        Node *temp = new Node(d);
        tail = temp;
        head = temp;
    }
    else
    {
        Node *temp = new Node(d);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}
void insertAtPosition(Node *&tail, Node *&head, int position, int d)
{
    // insert at start
    if (position == 1)
    {
        insertAtHead(tail, head, d);
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
        insertAttail(tail, head, d);
        return;
    }

    // creating a node for d
    Node *nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
}
void deleteNode(int position, Node *&head)
{
    // deletion at starting
    if (position == 1)
    {
        Node *temp = head;
       temp->next->prev= NULL;
       head= temp->next;
       temp->next=NULL;
       delete temp;
       
    }
    else
    {
        // deleting any middle node or last node
        Node *curr = head; // curr == current
        Node *prev = NULL;

        int cnt = 1;
        while (cnt < position)
        {
            prev = curr;
            curr = curr->next; // current ko aage badhaya
            cnt++;
        }
      curr->prev=NULL;
      prev->next=curr->next;
      curr->next=NULL;

        delete curr;
    }
}

int main()
{

    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;
    print(head);
    insertAtHead(tail, head, 5);
    print(head);
    insertAtHead(tail, head, 6);
    print(head);
    insertAtHead(tail, head, 8);
    print(head);
    insertAttail(tail, head, 3);
    print(head);
    insertAtPosition(tail, head, 2, 100);
    print(head);
    insertAtPosition(tail, head, 7, 101);
    print(head);
    insertAtPosition(tail, head, 8, 25);
    print(head);
    deleteNode(8, head);
    print(head);
    
    return 0;
}