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