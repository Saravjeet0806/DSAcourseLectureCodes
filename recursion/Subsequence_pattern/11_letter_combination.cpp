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


solve("23", "", 0)
│
├── output = "a" → solve("23", "a", 1)
│   ├── output = "ad" → solve("23", "ad", 2) ✅ push "ad"
│   ├── output = "ae" → solve("23", "ae", 2) ✅ push "ae"
│   └── output = "af" → solve("23", "af", 2) ✅ push "af"
│
├── output = "b" → solve("23", "b", 1)
│   ├── output = "bd" → solve("23", "bd", 2) ✅ push "bd"
│   ├── output = "be" → solve("23", "be", 2) ✅ push "be"
│   └── output = "bf" → solve("23", "bf", 2) ✅ push "bf"
│
└── output = "c" → solve("23", "c", 1)
    ├── output = "cd" → solve("23", "cd", 2) ✅ push "cd"
    ├── output = "ce" → solve("23", "ce", 2) ✅ push "ce"
    └── output = "cf" → solve("23", "cf", 2) ✅ push "cf"
