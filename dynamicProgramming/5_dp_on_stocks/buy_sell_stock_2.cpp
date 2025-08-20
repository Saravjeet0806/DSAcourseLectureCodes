//recursion approach
class Solution {
public:
    int helper(int ind, int buy, vector<int>& prices) {
        if (ind == prices.size()) return 0;

        int profit;
        if (buy) {
            profit = max(-prices[ind] + helper(ind + 1, 0, prices),
                         0 + helper(ind + 1, 1, prices));
        } else {
            profit = max(prices[ind] + helper(ind + 1, 1, prices),
                         0 + helper(ind + 1, 0, prices));
        }
        return profit;
    }

    int maxProfit(vector<int>& prices) {
        return helper(0, 1, prices);  
    }
};

//memoization 
class Solution {
public:
    int helper(int ind, int buy, vector<int>& prices, vector<vector<int>>&dp) {
        if (ind == prices.size()) return 0;
        int n = prices.size();
        int profit;
        if(dp[ind][buy]!= -1) return dp[ind][buy];
        if (buy) {
            profit = max(-prices[ind] + helper(ind + 1, 0, prices, dp),
                         0 + helper(ind + 1, 1, prices, dp));
        } else {
            profit = max(prices[ind] + helper(ind + 1, 1, prices, dp),
                         0 + helper(ind + 1, 0, prices, dp));
        }
        return  dp[ind][buy]= profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n, vector<int>(2,-1));
        return helper(0, 1, prices, dp);  
    }
};

//tabulation
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        // Base case: dp[n][buy] = 0 (no profit when no days left)

        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                if (buy) {
                    dp[ind][buy] = max(-prices[ind] + dp[ind + 1][0],
                                       0 + dp[ind + 1][1]);
                } else {
                    dp[ind][buy] = max(prices[ind] + dp[ind + 1][1],
                                       0 + dp[ind + 1][0]);
                }
            }
        }

        return dp[0][1];  // start from day 0 with option to buy
    }
};
