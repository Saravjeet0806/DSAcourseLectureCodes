//recursion
class Solution {
public:
    int count(int ind1, string text1, int ind2, string text2){
        if(ind1<0 || ind2<0){
            return 0;
        }
        if(text1[ind1]==text2[ind2]) {
            return 1+count(ind1-1, text1, ind2-1, text2);
        }

        return max(count(ind1-1, text1, ind2, text2), count(ind1, text1, ind2-1, text2));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n= text1.length();
        int m = text2.length();
        return count(n-1, text1, m-1, text2);
    }
};

//memoization ..it also got tle because of a large case
class Solution {
public:
    int count(int ind1, string text1, int ind2, string text2, vector<vector<int>>&dp){
        if(ind1<0 || ind2<0){
            return 0;
        }
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        if(text1[ind1]==text2[ind2]) {
            return 1+count(ind1-1, text1, ind2-1, text2, dp);
        }

        dp[ind1][ind2] = max(count(ind1-1, text1, ind2, text2, dp), count(ind1, text1, ind2-1, text2, dp));
        return dp[ind1][ind2];
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n= text1.length();
        int m = text2.length();
        int l = max(n,m);
        vector<vector<int>>dp(n, vector<int>(l, -1));
        return count(n-1, text1, m-1, text2, dp);
    }
};

//tabulation
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1)); // Create a DP table //right shift so that there are no negative integers..

        // Initialize the base cases
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }
        for (int i = 0; i <= m; i++) {
            dp[0][i] = 0;
        }

        // Fill in the DP table to calculate the length of LCS
        for (int ind1 = 1; ind1 <= n; ind1++) {
            for (int ind2 = 1; ind2 <= m; ind2++) {
                if (text1[ind1 - 1] == text2[ind2 - 1])
                    dp[ind1][ind2] = 1 +  dp[ind1 - 1][ind2 - 1]; // Characters match, increment LCS length
                else
                    dp[ind1][ind2] = max( dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]); // Characters 
            }
        }

        return dp[n][m]; // Return the length of the Longest Common Subsequence
    }
};

// Why Do We Shift (Right-Shift or Index Shift)?
// We shift the indices to avoid dealing with negative indices and to simplify base cases.

// For example:

// If you didn't shift, your loop would have to handle dp[0][0] when comparing text1[-1] and text2[-1] (which is invalid).

// Instead, by shifting, you use:

// dp[i][j] to represent the LCS of the first i characters of text1 and the first j characters of text2.

// This lets you access text1[i-1] and text2[j-1], which are valid indices.