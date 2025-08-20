class Solution {
public:
    int helper(int ind, int buy, vector<int>& prices, int fees, vector<vector<int>>&dp) {
        if (ind >= prices.size()) return 0;
        int n = prices.size();
        int profit;
        if(dp[ind][buy]!= -1) return dp[ind][buy];
        if (buy) {
            profit = max(-prices[ind] + helper(ind + 1, 0, prices, fees, dp),
                         0 + helper(ind + 1, 1, prices, fees, dp));
        } else {
            profit = max(prices[ind]-fees + helper(ind + 1, 1, prices, fees, dp),
                         0 + helper(ind + 1, 0, prices, fees, dp));
        }
        return  dp[ind][buy]= profit;
    }

    int maxProfit(vector<int>& prices, int fees) {
        int n = prices.size();
        vector<vector<int>>dp(n, vector<int>(2,-1));
        return helper(0, 1, prices, fees, dp);  
    }
};