//problem link https://www.geeksforgeeks.org/problems/nearly-sorted-1587115620/1

class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        int n = arr.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        
        int index=0;
        
        for(int i=0; i<n; i++){
            pq.push(arr[i]);
            
            if(pq.size()>k){
                int x = pq.top();
                pq.pop();
                arr[index]=x;
                index++;
            }
        }
        while(pq.size()>0){
            int x = pq.top();
                pq.pop();
                arr[index]=x;
                index++;
        }
    }
};