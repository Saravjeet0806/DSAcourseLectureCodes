class Solution {
public:
    int f(int ind, int amount, vector<int>&coins){
         if (ind == 0) {
            if (amount % coins[0] == 0) return amount / coins[0];
            return 1e9;
        }
        int notTake = f(ind - 1, amount, coins);
        int take = 1e9;
        if (coins[ind] <= amount)
            take = 1 + f(ind, amount - coins[ind], coins);
        return min(notTake, take);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int ans = f(n - 1, amount, coins);
        return ans >= 1e9 ? -1 : ans;
    }
};

//memoization
class Solution {
public:
    int f(int ind, int amount, vector<int>&coins, vector<vector<int>>&dp){
         if (ind == 0) {
            if (amount % coins[0] == 0) return amount / coins[0];
            return 1e9;
        }
        if(dp[ind][amount]!=-1) return dp[ind][amount];
        int nottake = f(ind - 1, amount, coins, dp);
        int take = 1e9;
        if (coins[ind] <= amount)
            take = 1 + f(ind, amount - coins[ind], coins, dp);
        dp[ind][amount] = min(nottake, take);
        return dp[ind][amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1, -1));
        int ans = f(n - 1, amount, coins, dp);
        return ans >= 1e9 ? -1 : ans;
    }
};

//bottom up approach
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1, 1e9));

         // Base Case: Only using the first coin
        for (int amt = 0; amt <= amount; amt++) {
            if (amt % coins[0] == 0) {
                dp[0][amt] = amt / coins[0];
            }
        }
        // Fill the DP table
        for (int ind = 1; ind < n; ind++) {
            for (int amt = 0; amt <= amount; amt++) {
                int notTake = dp[ind - 1][amt];
                int take = 1e9;
                if (coins[ind] <= amt) {
                    take = 1 + dp[ind][amt - coins[ind]];
                }
                dp[ind][amt] = min(take, notTake);
            }
        }

        int result = dp[n - 1][amount];
        return result >= 1e9 ? -1 : result;
    }
};
