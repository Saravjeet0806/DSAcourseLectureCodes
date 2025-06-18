// https://www.geeksforgeeks.org/problems/-minimum-number-of-coins4426/1

class Solution {
  public:
    vector<int> minPartition(int N) {
        vector<int>arr = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
        
        vector<int> ans;
        
        for(int i=0; i<arr.size(); i++){
            while(N>=arr[i]){
                N-=arr[i];
                ans.push_back(arr[i]);
            }
        }
        return ans;
    }
};