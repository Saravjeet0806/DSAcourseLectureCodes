class Solution {
public:
    bool helper(int i, int j, string p, string s){
        if(i<0 && j<0) return true;
        if(i<0 && j>=0) return false;
        if(j<0 && i>=0){
            for(int index=0; index<=i; index++){
                if(p[index]!='*'){
                    return false;
                }
            }
            return true;
        }

        if(p[i]==s[j] || p[i]=='?'){
            return helper(i-1, j-1, p, s);
        }

        if(p[i]=='*'){
            // * matches empty or one character
            return helper(i-1, j, p, s) || helper(i, j-1, p, s);
        }

        return false;
    }

    bool isMatch(string s, string p) {
        int n = p.length();
        int m = s.length();
        return helper(n-1, m-1, p, s);
    }
};

//memoization
class Solution {
public:
    bool helper(int i, int j, string p, string s, vector<vector<int>>&dp){
        if(i<0 && j<0) return true;
        if(i<0 && j>=0) return false;
        if(j<0 && i>=0){
            for(int index=0; index<=i; index++){
                if(p[index]!='*'){
                    return false;
                }
            }
            return true;
        }

        if(p[i]==s[j] || p[i]=='?'){
            return dp[i][j] = helper(i-1, j-1, p, s, dp);
        }

        if(p[i]=='*'){
            // * matches empty or one character
            return dp[i][j] = helper(i-1, j, p, s, dp) || helper(i, j-1, p, s, dp);
        }

       return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        int n = p.length();
        int m = s.length();
        
        vector<vector<int>>dp(n, vector<int>(m, -1));
        return helper(n-1, m-1, p, s, dp);

    }
};

//tabulation
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = p.length();
        int m = s.length();

        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[0][0] = true;

        // pattern is empty, string is not => false
        for (int j = 1; j <= m; j++) {
            dp[0][j] = false;
        }

        // string is empty, pattern can be true only if all pattern chars are '*'
        for (int i = 1; i <= n; i++) {
            bool flag = true;
            for (int index = 1; index <= i; index++) {
                if (p[index - 1] != '*') {
                    flag = false;
                    break;
                }
            }
            dp[i][0] = flag;
        }

        // fill DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (p[i - 1] == s[j - 1] || p[i - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[i - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                } else {
                    dp[i][j] = false;
                }
            }
        }

        return dp[n][m];
    }
};
