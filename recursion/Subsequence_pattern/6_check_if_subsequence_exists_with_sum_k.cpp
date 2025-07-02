class Solution {
  public:
    bool helper(int index, int sum, vector<int>&arr, int k){
        if(sum==k) return true;
        
        if(index<0) return false;
        
        if(helper(index-1, sum+arr[index], arr, k)) return true;
        
        if(helper(index-1, sum, arr, k)) return true;
        
        return false;
        
    }
    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
        return helper(n-1, 0, arr, k);
    }
};

//memoization
class Solution {
  public:
    bool helper(int index, int sum, vector<int>&arr, int k, vector<vector<int>>&dp){
        if(sum==k) return true;
        if(index<0) return false;
        
        if (dp[index][sum] != -1) return dp[index][sum];
        
        bool pick = false;
        if (sum + arr[index] <= k) {
            pick = helper(index - 1, sum + arr[index], arr, k, dp);
        }
        
        bool notPick = helper(index-1, sum, arr, k, dp);
        
       return dp[index][sum] = (pick || notPick);
        
    }
    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
          vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        return helper(n-1, 0, arr, k, dp);
    }
};