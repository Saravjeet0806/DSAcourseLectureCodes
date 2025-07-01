class Solution {
public:
    int count(int i, int j, string s, string t, vector<vector<int>>&dp){
        if(j<0) return 1;
         if(i<0) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i] == t[j]){
            return dp[i][j] = count(i-1, j-1, s, t, dp) + count(i-1, j, s, t, dp); //characters match and we move both pointers or characters match but we want other possibilities
        } 
        else{ //character does not match
            return dp[i][j] =  count(i-1, j, s, t, dp); 
        }

    }
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<vector<int>>dp(n, vector<int>(m, -1));
        return count(n-1, m-1, s, t, dp);
    }
};

//bottom up 
class Solution {
public:
     int M = 1000000007;
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));

        // Initialize base case: empty target string
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        // Fill the table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j])%M;
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][m];
    }
};
