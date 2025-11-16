#include <bits/stdc++.h> 
class Queue {
    int *arr;
    int rear; 
    int qfront;
    int size;
public:
    Queue() {
      size=100001;;
      arr= new int[size];
      qfront=0;
      rear=0;
    }
    
    bool isEmpty() {
        
        if(qfront==rear)
        return true;
        else
        return false;
    }

    void enqueue(int data) {
        if(rear==size){
            cout<<"Queue is full"<<endl;
        }
        else{
            arr[rear]=data;
            rear++;
        }
    }

    int dequeue() {
        if(qfront==rear){
            return -1;
        }
        else{
            int ans=arr[qfront];
            arr[qfront]=-1;
            qfront++;
            if(qfront==rear){
                qfront=0; rear=0;
            }
            return ans;
        }
    }

    int front() {
        if(qfront==rear){
            return -1;
        }
        else{
            return arr[qfront];
        }
    }
};


//better
#include <bits/stdc++.h>
using namespace std;

class Queue {
private:
    vector<int> arr;
    int start, end, currSize, maxSize;

public:
    // Constructor
    Queue(int size) : arr(size), start(-1), end(-1), currSize(0), maxSize(size) {}

    bool isEmpty() const {
        return currSize == 0;
    }

    bool isFull() const {
        return currSize == maxSize;
    }

    void enqueue(int val) {
        if (isFull()) {
            throw runtime_error("Queue is full");
        }
        if (start == -1) {   // first element
            start = 0;
        }
        end = (end + 1) % maxSize;
        arr[end] = val;
        currSize++;
    }

    int dequeue() {
        if (isEmpty()) {
            throw runtime_error("Queue is empty");
        }
        int result = arr[start];
        if (currSize == 1) { 
            start = -1;
            end = -1;
        } else {
            start = (start + 1) % maxSize;
        }
        currSize--;
        return result;
    }

    int front() const {
        if (isEmpty()) {
            throw runtime_error("Queue is empty");
        }
        return arr[start];
    }

    int size() const {
        return currSize;
    }
};

// Example usage
int main() {
    Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front = " << q.front() << "\n";
    cout << "Dequeued = " << q.dequeue() << "\n";
    cout << "Front after dequeue = " << q.front() << "\n";
    cout << "Size = " << q.size() << "\n";

    return 0;
}
