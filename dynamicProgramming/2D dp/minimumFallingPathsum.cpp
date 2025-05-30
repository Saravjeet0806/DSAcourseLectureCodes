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

//tabulation
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size(); //  columns

        vector<vector<int>> dp(n, vector<int>(m, 0));

        for (int j = 0; j < m; j++) {
            dp[0][j] = matrix[0][j];
        }

        // Iterate through the matrix rows starting from the second row
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int up = matrix[i][j] + dp[i - 1][j];
                // Left diagonal
                int leftDiagonal = matrix[i][j];
                if (j - 1 >= 0) {
                    leftDiagonal += dp[i - 1][j - 1];
                } else {
                    leftDiagonal += 1e9; // A very large negative value to
                                         // represent an invalid path
                }

                // Right diagonal direction (if it's a valid move)
                int rightDiagonal = matrix[i][j];
                if (j + 1 < m) {
                    rightDiagonal += dp[i - 1][j + 1];
                } else {
                    rightDiagonal += 1e9; // A very large negative value to
                                          // represent an invalid path
                }

                // Store the maximum of the three paths in dp
                dp[i][j] = min(up, min(leftDiagonal, rightDiagonal));
            }
        }
        int mini = INT_MAX;
        for (int j = 0; j < m; j++) {
            mini = min(mini, dp[n - 1][j]);
        }

        return mini;
    }
};