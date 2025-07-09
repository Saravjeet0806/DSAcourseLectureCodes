class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(vector<int>& arr) {
        vector<int> ans;
        int n = arr.size();
        int maxRight = arr[n-1];
        ans.push_back(maxRight);
        
        for(int i=n-2; i>=0; i--){
            if(arr[i]>=maxRight){
                maxRight = arr[i];
                ans.push_back(maxRight);
            }
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};