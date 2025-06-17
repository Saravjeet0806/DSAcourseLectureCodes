//https://www.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1

class Solution {
  public:
    int minCost(vector<int>& arr) {
       priority_queue<int, vector<int>, greater<int>>pq;
       
       for(int i : arr){
           pq.push(i);
       }
       
       int res =0;

       while(pq.size()>1){
           int first = pq.top();
           pq.pop();
           int second = pq.top();
           pq.pop();
           res+= first + second;
           
           pq.push(first+second);
       }
       
       return res;
       
        
    }
};