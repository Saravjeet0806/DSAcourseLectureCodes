class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.length();
        int m = str2.length();
        
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1)); 
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }
        for (int i = 0; i <= m; i++) {
            dp[0][i] = 0;
        }

        for (int ind1 = 1; ind1 <= n; ind1++) {
            for (int ind2 = 1; ind2 <= m; ind2++) {
                if (str1[ind1 - 1] == str2[ind2 - 1])
                    dp[ind1][ind2] = 1 +  dp[ind1 - 1][ind2 - 1]; 
                else
                    dp[ind1][ind2] = max( dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);  
            }
        }

        string ans ="";

        int i = n, j = m;

        while(i>0 && j>0){  //traversing the dp array
            if(str1[i-1]==str2[j-1]){
                ans+=str1[i-1];
                i--;
                j--;
            }
            else if(dp[i-1][j]>dp[i][j-1]){
                ans+=str1[i-1]; 
                i--;
            }
            else{
                ans+=str2[j-1];
                j--;
            }
        }

        while(i>0){  //add the remaining portion of string
            ans+=str1[i-1];
            i--;
        }
        while(j>0){
            ans+=str2[j-1];  //add the remaining portion of string
            j--;
        }

        reverse(ans.begin(), ans.end());

        return ans;

    }
};