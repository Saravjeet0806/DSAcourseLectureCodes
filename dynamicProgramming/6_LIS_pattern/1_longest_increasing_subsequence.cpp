//recursion
class Solution {
public:
    int helper(int ind, int prev_ind, vector<int>&nums, int n){
        if(ind == n) return 0;

        int notTake = 0 + helper(ind+1, prev_ind, nums, n);
        int Take=0;

        if(prev_ind==-1 || nums[ind]>nums[prev_ind]){
             Take = 1 + helper(ind+1, ind, nums, n);
        }

        int length = max(notTake, Take);

        return length;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n= nums.size();
        return helper(0, -1, nums, n);
    }
};

//memoization
class Solution {
public:
    int helper(int ind, int prev_ind, vector<int>& nums, int n, vector<vector<int>>& dp) {
        if (ind == n) return 0;
        if (dp[ind][prev_ind + 1] != -1) return dp[ind][prev_ind + 1];

        int notTake = 0 + helper(ind + 1, prev_ind, nums, n, dp);
        int Take = 0;
        if (prev_ind == -1 || nums[ind] > nums[prev_ind]) {
            Take = 1 + helper(ind + 1, ind, nums, n, dp);
        }

        int length = max(notTake, Take);
        return dp[ind][prev_ind + 1] = length;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return helper(0, -1, nums, n, dp);
    }
};  
//tabulation
 int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n + 1, 0));
        for(int ind = n-1; ind>=0; ind--){
            for(int prev_ind = ind-1; prev_ind>=-1; prev_ind--){
                           int notTake = 0 + dp[ind + 1][prev_ind+1];
                            int Take = 0;
                            if (prev_ind == -1 || nums[ind] > nums[prev_ind]) {
                                Take = 1 + dp[ind + 1][ind+1];
                            }
                            int length = max(notTake, Take);
                            dp[ind][prev_ind + 1] = length;
            }
        }
        return dp[0][0];