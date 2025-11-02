class Solution {
public:
    
    long long solve(string &s, int i, int j, int isTrue,
                    vector<vector<vector<long long>>> &dp){
        if(i > j) return 0;
        if(i == j){
            if(isTrue) return s[i] == 'T';
            else return s[i] == 'F';
        }
        
        if(dp[i][j][isTrue] != -1) return dp[i][j][isTrue];

        long long ways = 0;

        for(int ind = i + 1; ind <= j - 1; ind += 2){
            long long lT = solve(s, i, ind-1, 1, dp);
            long long lF = solve(s, i, ind-1, 0, dp);
            long long rT = solve(s, ind+1, j, 1, dp);
            long long rF = solve(s, ind+1, j, 0, dp);

            if(s[ind] == '&'){
                if(isTrue) ways += lT * rT;
                else ways += lF*rF + lT*rF + lF*rT;
            }
            else if(s[ind] == '|'){
                if(isTrue) ways += lT*rT + lT*rF + lF*rT;
                else ways += lF * rF;
            }
            else { // XOR '^'
                if(isTrue) ways += lT*rF + lF*rT;
                else ways += lT*rT + lF*rF;
            }
        }

        return dp[i][j][isTrue] = ways;
    }

    int countWays(string &s) {
        int n = s.size();
        vector<vector<vector<long long>>> dp(n,
            vector<vector<long long>>(n, vector<long long>(2, -1)));
        
        return (int)solve(s, 0, n-1, 1, dp);
    }
};
