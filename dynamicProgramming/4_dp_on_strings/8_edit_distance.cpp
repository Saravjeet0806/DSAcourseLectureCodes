//recursive
class Solution {
public:
    int count(int i, int j, string& s1, string& s2){
        if(i < 0) return j + 1; // Insert all remaining characters of s2
        if(j < 0) return i + 1; // Delete all remaining characters of s1

        if(s1[i] == s2[j])
            return count(i - 1, j - 1, s1, s2); // Characters match, move both

        // Perform insert, delete, or replace
        int insertOp = 1 + count(i, j - 1, s1, s2);
        int deleteOp = 1 + count(i - 1, j, s1, s2);
        int replaceOp = 1 + count(i - 1, j - 1, s1, s2);

        return min({insertOp, deleteOp, replaceOp});
    }

    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        return count(n - 1, m - 1, word1, word2);
    }
};

//memoization
class Solution {
public:
    int count(int i, int j, string& s1, string& s2, vector<vector<int>>&dp){
        if(i < 0) return j + 1; // Insert all remaining characters of s2
        if(j < 0) return i + 1; // Delete all remaining characters of s1

        if(s1[i] == s2[j])
            return count(i - 1, j - 1, s1, s2, dp); // Characters match, move both
        if(dp[i][j]!=-1) return dp[i][j];    

        // Perform insert, delete, or replace
        int insertOp = 1 + count(i, j - 1, s1, s2, dp);
        int deleteOp = 1 + count(i - 1, j, s1, s2 , dp);
        int replaceOp = 1 + count(i - 1, j - 1, s1, s2 ,dp);

        dp[i][j] =  min({insertOp, deleteOp, replaceOp});
        return dp[i][j];
    }

    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        vector<vector<int>>dp(n, vector<int>(m, -1));
        return count(n - 1, m - 1, word1, word2, dp);
    }
};

//tabulation
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        // Initialize the base case
        for (int i = 0; i <= n; i++) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= m; j++) {
            dp[0][j] = j;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    // If the characters match, no additional cost
                    dp[i][j] = dp[i - 1][j - 1];
                } else {  //insert, delete, replace
                    dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
                }
            }
        }
        return dp[n][m];
    }
};