//memoization 
class Solution {
private:
    int solve(int i, int j, vector<vector<int>>&arr, int n, vector<vector<int>>dp){
        if(dp[i][j]!=-1) return dp[i][j];
        if(i==n-1) return arr[i][j];
        int down = arr[i][j] + solve(i+1, j, arr, n, dp);
        int diagonal = arr[i][j] + solve(i+1, j+1, arr, n, dp);

        return dp[i][j]= min(down, diagonal);
    }    
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(0, 0, triangle, n, dp);
    }
};