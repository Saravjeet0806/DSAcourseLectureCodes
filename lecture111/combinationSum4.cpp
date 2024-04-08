//recursion + memoization
class Solution {
private: 
int solve(vector<int>&nums, int target, vector<int> &dp) {
    if(target<0)
    return 0;
    if(target==0)
    return 1;

    if(dp[target]!=-1)
    return dp[target];
    int ans=0;
    for(int i=0; i<nums.size(); i++){
        ans+=solve(nums, target-nums[i], dp);
    }
    dp[target]=ans;
    return dp[target];
}   
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int>dp(target+1, -1);
        return solve(nums, target,dp);
    }
};


//tabulation
#include <bits/stdc++.h> 
int solveTab(vector<int>&num, int tar ){
    vector<int>dp(tar+1, 0);

    dp[0]=1;
    //traversing from target1 to tar
    for(int i=1; i<=tar; i++){
        //traversing on num vector
        for(int j=0; j<num.size(); j++){
            if(i-num[j]>=0)
            dp[i]+=dp[i-num[j]];
        }
    }
    return dp[tar];
    
}
int findWays(vector<int> &num, int tar)
{
 
   return solveTab(num, tar);
}