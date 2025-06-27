//memoization
class Solution {
public:
    int f(int ind, int target, vector<int>& num, vector<vector<int>>& dp) {
        // Base case
        if (ind == 0) {
            if (target == 0 && num[0] == 0) return 2; // pick and not pick
            if (target == 0 || target == num[0]) return 1;
            return 0;
        }

        if (dp[ind][target] != -1) return dp[ind][target];

        int notTake = f(ind - 1, target, num, dp);
        int take = 0;
        if (num[ind] <= target)
            take = f(ind - 1, target - num[ind], num, dp);

        return dp[ind][target] = notTake + take;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totSum = 0;
        for (int i = 0; i < n; i++) {
            totSum += nums[i];
        }

        // Checking for edge cases
        if (totSum - target < 0 || (totSum - target) % 2 != 0)
            return 0; // Not possible to achieve the target sum

        int sum = (totSum - target) / 2;

        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        return f(n - 1, sum, nums, dp);
    }
};

//tabulation
class Solution {
public:
    int findWays(vector<int> &num, int tar) {
    int n = num.size();

    vector<vector<int>> dp(n, vector<int>(tar + 1, 0));

    if (num[0] == 0)
        dp[0][0] = 2;  // 2 cases - pick and not pick
    else
        dp[0][0] = 1;  // 1 case - not pick

    if (num[0] != 0 && num[0] <= tar)
        dp[0][num[0]] = 1;  // 1 case - pick

    for (int ind = 1; ind < n; ind++) {
        for (int target = 0; target <= tar; target++) {

            int notTaken = dp[ind - 1][target];

            int taken = 0;
            if (num[ind] <= target)
                taken = dp[ind - 1][target - num[ind]];

            dp[ind][target] = (notTaken + taken);
        }
    }
    return dp[n - 1][tar];
}
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totSum = 0;
        for (int i = 0; i < n; i++) {
            totSum += nums[i];
        }

        // Checking for edge cases
        if (totSum - target < 0 || (totSum - target) % 2 != 0)
            return 0; // Not possible to achieve the target sum

        return findWays(nums, (totSum - target) / 2);
    }
}; //convert it into memoization