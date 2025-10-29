class Solution {
public:
    int f(int i, int j, vector<int>&cuts, vector<vector<int>>&dp){
        if(i>j) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int cost, mini=1e9;

        for(int ind = i; ind<=j; ind++){
            cost = cuts[j+1] - cuts[i-1] + f(i, ind-1, cuts, dp) + f(ind+1, j, cuts, dp);
            mini = min(mini, cost);
        }
        dp[i][j] = mini;
        return dp[i][j];
    }
    int minCost(int n, vector<int>& cuts) {
         cuts.push_back(n);
         cuts.push_back(0);
         sort(cuts.begin(), cuts.end());
         int m = cuts.size();
         vector<vector<int>>dp(m, vector<int>(m, -1));

         return f(1, m-2, cuts, dp);
    }
};