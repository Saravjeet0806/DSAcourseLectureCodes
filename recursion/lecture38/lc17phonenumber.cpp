class Solution {
private:
void solve(string digit, string output, int index, vector<string> &ans, string mapping[]){
       //base case
       if(index>=digit.length()){
           ans.push_back(output);
           return; 
       }
       int number = digit[index]-'0';     //for converting string to number
       string value = mapping[number];
       for(int i= 0; i<value.length(); i++){
           output.push_back(value[i]);
           solve(digit, output, index+1, ans, mapping);
           output.pop_back();    //for backtracking
       }
}

public:
    vector<string> letterCombinations(string digit) {
        vector<string> ans;
        if(digit.length()==0){     //for corner cases
            return ans;
        }
        string output;
        int index=0;
        string mapping[10]={"", "", "abc", "def", "ghi","jkl", "mno", "pqrs", "tuv", "wxyz"};
        solve(digit, output, index, ans, mapping);
        return ans;
    }
};