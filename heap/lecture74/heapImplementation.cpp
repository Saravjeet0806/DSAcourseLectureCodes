#include <bits/stdc++.h>
using namespace std;

class Heap
{
public:
    int arr[100];
    int size;

    Heap()
    {
        arr[0] = -1;
        size = 0;
    }

    void insert(int val)
    {
        int index = ++size;
        arr[index] = val;

        while (index > 1)
        {
            int parent = index / 2;

            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent; //index is now parent index
            }
            else
            {
                return;
            }
        }
    }
    void print()
    {
        cout << "Max Heap : ";
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    void deleteRoot()
    {
        if (size == 0)
        {
            cout << "Heap is empty\n";
            return;
        }
        // 1st step
        arr[1] = arr[size]; //replace the root with the last element
        // 2nd step
        size--; //reduce the size of heap
        // 3rd step
        int i = 1; //start from the root
        while (i < size)
        {
            int leftInd = 2 * i;
            int rightInd = 2 * i + 1;
            /* Modification - 1 */
            if (leftInd <= size && arr[i] < arr[leftInd] && arr[leftInd] > arr[rightInd])
            {
                swap(arr[i], arr[leftInd]);
                i = leftInd;
            }
            /* Modification - 2 */
            else if (rightInd <= size && arr[i] < arr[rightInd] && arr[rightInd] > arr[leftInd])
            {
                swap(arr[i], arr[rightInd]);
                i = rightInd;
            }
            else
            {
                return;
            }
        }
    }
};
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= n && arr[largest] < arr[left])  //<=for one based indexing
    {
        largest = left;
    }
    if (right <= n && arr[largest] < arr[right])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}
void heapSort(int arr[], int n){
    int size=n;
    while(size>1){
        //step1 swap
        swap(arr[size],arr[1]);
        size--;
        //step 2
        heapify(arr,size,1);
    }
}
int main()
{
    Heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();
    h.deleteRoot();
    h.print();

    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, n, i);
    }
    cout << "printing the array" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    //heapSort
    heapSort(arr, n);
    cout<<"printing sorted array"<<endl;
     for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout<<"using priority queue here"<<endl;
    //maxheap
    priority_queue<int> pq;
    pq.push(4);
   pq.push(2);
   pq.push(5);
   pq.push(3);
   cout<<"element at top "<<pq.top()<<endl;

   //minheap
   priority_queue<int, vector<int>, greater<int>> minheap;
   minheap.push(4);
     minheap.push(5);
      minheap.push(3);
      minheap.push(4);
       cout<<"element at top "<<minheap.top()<<endl;

       //also explore top size and empty functions of priority queues
       
    return 0;
}