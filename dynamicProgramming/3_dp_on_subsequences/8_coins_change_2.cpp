//recursive
class Solution {
public:
    long count(int ind, int amount, vector<int>&coins){
        if(ind==0 ) return (amount%coins[ind] == 0);

        long notpick = count(ind-1, amount, coins);
        long pick = 0;
        if(coins[ind]<=amount) pick = count(ind, amount-coins[ind], coins);
        return pick+notpick;

    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        return count(n-1, amount, coins);
    }
};


//memoization
class Solution {
public:
    long count(int ind, int amount, vector<int>&coins, vector<vector<int>>&dp){
        if(ind==0 ) return (amount%coins[ind] == 0);

        if(dp[ind][amount]!=-1) return dp[ind][amount];

        long notpick = count(ind-1, amount, coins, dp);
        long pick = 0;
        if(coins[ind]<=amount) pick = count(ind, amount-coins[ind], coins, dp);
        dp[ind][amount] =  pick+notpick;
        return dp[ind][amount];

    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1, -1));
        return count(n-1, amount, coins, dp);
    }
};