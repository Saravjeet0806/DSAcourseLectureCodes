class Solution {
public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));

        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }

        if (arr[0] <= sum) {
            dp[0][arr[0]] = true;
        }

        for (int ind = 1; ind < n; ind++) {
            for (int j = 1; j <= sum; j++) {
                bool notTaken = dp[ind - 1][j];
                bool taken = false;
                if (arr[ind] <= j) {
                    taken = dp[ind - 1][j - arr[ind]];
                }
                dp[ind][j] = notTaken || taken;
            }
        }

        return dp[n - 1][sum];
    }
    bool canPartition(vector<int>& nums) {
        int totsum=0;
        for(int i =0;i<nums.size(); i++){
            totsum+=nums[i];
        }
        int sum = totsum/2;
        if(totsum%2) return false;

        return isSubsetSum(nums, sum);

    }
};