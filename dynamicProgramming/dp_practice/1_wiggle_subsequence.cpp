class Solution {
public:
    int solve(int index, int isUp, vector<int>&nums, vector<vector<int>>&dp){
       if(index == nums.size()){
          return 0;
       } 
       if(dp[index][isUp]!=-1) return dp[index][isUp];

       int notTake = solve(index+1, isUp, nums, dp);
       int take =0;
       if((isUp && nums[index]<nums[index-1]) ||(!isUp && nums[index]>nums[index-1])){
        take = 1+ solve(index+1, !isUp, nums, dp);
       }

       return dp[index][isUp] = max(take, notTake);
    }
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n, vector<int>(2, -1));

        return max(solve(1, 1, nums, dp), solve(1, 0, nums, dp)) + 1;
    }
};