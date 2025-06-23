//brute force 
int solve(int i, vector<int>& nums) {
    if (i == 0) return nums[0];
    if (i < 0) return 0;

    int rob = nums[i] + solve(i - 2, nums);
    int skip = 0+ solve(i - 1, nums);

    return max(rob, skip);
}

//top down 
int solve(int i, vector<int>& nums, vector<int>& dp) {
    if (i == 0) return nums[0];
    if (i < 0) return 0;
    if (dp[i] != -1) return dp[i];

    int rob = nums[i] + solve(i - 2, nums, dp);
    int skip = solve(i - 1, nums, dp);

    return dp[i] = max(rob, skip);
}
//bottom up 
#include <bits/stdc++.h>
int maxMoneyLooted(vector<int> &houses, int n)
{
    if (n == 0) return 0;
    if (n == 1) return houses[0];

    vector<int> dp(n, 0);

    dp[0] = houses[0];
    dp[1] = max(houses[0], houses[1]);

    for (int i = 2; i < n; i++) {
        int rob = houses[i] + dp[i - 2];  // Include current, skip previous
        int skip = dp[i - 1];             // Exclude current, take previous
        dp[i] = max(rob, skip);
    }

    return dp[n - 1];
}




//space optimization approach 
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