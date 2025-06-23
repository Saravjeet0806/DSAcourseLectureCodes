class Solution {
public:
    int numDecodings(string s) {
        if(s.empty() || s[0] == '0') return 0;

        int n = s.length();
        vector<int> dp(n+1, 0);  //dp[i] == no. of ways to decode the ith character
        dp[0]=1;
        dp[1]=1;
       
         for (int i = 2; i <= n; i++) {
            int oneDigit = s[i - 1] - '0';        // s[i-1] → current character
            int twoDigits = stoi(s.substr(i - 2, 2)); // s[i-2] and s[i-1] → last 2 characters

            if (oneDigit != 0) {
                dp[i] += dp[i - 1];
            }

            if (10 <= twoDigits && twoDigits <= 26) {
                dp[i] += dp[i - 2];
            }
        }


        return dp[n];
    }
};