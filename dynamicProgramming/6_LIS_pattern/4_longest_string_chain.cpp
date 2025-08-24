class Solution {
public:
     bool checkPossible(string &a, string &b){
        if(a.size() != b.size()+1) return false;  //increase by 1 
        int first=0;
        int second=0;
        
         while (first < a.size()) {
            if (second < b.size() && a[first] == b[second]) {
                second++;
            }
            first++;
        }
        // Return true if `b` matches `a` after removing one character
        return second == b.size();
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), [](string &a, string &b) {
            return a.size() < b.size();
        });

        vector<int>dp(n, 1);
        int ans =1;
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(checkPossible(words[i], words[j]) && dp[j]+1 > dp[i]){
                    dp[i] = dp[j] +1;
                }
                ans = max(ans, dp[i]);
            }
        }
        return ans;
    }
};