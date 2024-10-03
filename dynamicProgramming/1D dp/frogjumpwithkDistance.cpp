class Solution {
 
  public:
    int minimizeCost(int k, vector<int>& arr) {
        int n=arr.size();
        vector<int> dp(n, INT_MAX); 
        dp[0] = 0;  
   
    for (int i = 1; i < n; i++) {
       
        for (int j = 1; j <= k; j++) {
            if (i - j >= 0) {  
                int jumpCost = dp[i - j] + abs(arr[i] - arr[i - j]);
                dp[i] = min(dp[i], jumpCost); 
            }
        }
    }
    
       return dp[n - 1];
    }
};