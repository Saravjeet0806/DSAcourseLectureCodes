//memoization gives tle
class Solution {
private:
    int getMaxUtil(int i, int j, int m, vector<vector<int>> &matrix, vector<vector<int>> &dp) {
    if (j < 0 || j >= m)
        return 1e9;
    if (i == 0)
        return matrix[0][j]; 
    
    if (dp[i][j] != -1)
        return dp[i][j]; 
    
    int up = matrix[i][j] + getMaxUtil(i - 1, j, m, matrix, dp);
    int leftDiagonal = matrix[i][j] + getMaxUtil(i - 1, j - 1, m, matrix, dp);
    int rightDiagonal = matrix[i][j] + getMaxUtil(i - 1, j + 1, m, matrix, dp);
    
    return dp[i][j] = min(up, min(leftDiagonal, rightDiagonal));
}   
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
         int n = matrix.size(); 
    int m = matrix[0].size();     
    vector<vector<int>> dp(n, vector<int>(m, -1));   

    int mini = INT_MAX;  
    for (int j = 0; j < m; j++) {
        int ans = getMaxUtil(n - 1, j, m, matrix, dp); 
        mini = min(mini, ans); 
    }
    
    return mini; 
    }
};