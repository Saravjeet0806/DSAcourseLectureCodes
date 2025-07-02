class Solution {
  public:
    void solve(int n, string output, vector<string>&ans){
        if (n == 0) {
            ans.push_back(output);
            return;
        }

        // Always safe to add '0'
        solve(n - 1, output + "0", ans);

        // Add '1' only if last character is not '1'
        if (output.empty() || output.back() != '1') {
            solve(n - 1, output + "1", ans);
        } 
    }
    vector<string> generateBinaryStrings(int num) {
       vector<string>ans;
       string output = "";
       solve(num, output, ans);
       return ans;
    }
}; 

 
 
                       ""
                     /   \
                 "0"       "1"
                /   \         \
            "00"   "01"      "10"
           /    \     \        \
      "000"  "001"   "010"    "100"
                             \
                             "101"
