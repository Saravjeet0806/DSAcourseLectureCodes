class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        //edge cases
        if (n == 0) // Check for an empty nums array
            return 0;
        else if (n == 1) // If only one house, rob that house
            return nums[0];
        vector<int> dp(n,0);

        dp[0]=nums[0];
        dp[1] = max(nums[0], nums[1]);  //robber can rob either first or second house

        for(int i=2; i<n; i++){
            int incl= dp[i-2]+nums[i];
            int excl=dp[i-1]+0;
            dp[i]=max(incl, excl);
        }
        return dp[n-1];
    }
};