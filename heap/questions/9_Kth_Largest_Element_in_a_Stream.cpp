class KthLargest {
    int num;
    priority_queue<int, vector<int>, greater<int>> pq;
public:
    KthLargest(int k, vector<int>& nums) {
        num = k; //stored in a public variable to use in add function
        for(auto i : nums){
            pq.push(i);
            if(pq.size()>k){ //minheap can only have k elements so that kth larget element is pq.top()
                pq.pop();
            }
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>num){
            pq.pop();
        }
        return pq.top(); //return the kth largest element
    }
};