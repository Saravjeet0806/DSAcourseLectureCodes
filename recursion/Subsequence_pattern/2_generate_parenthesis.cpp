class Solution {
public:
    void generate(int open, int close, string curr, vector<string>& res) {
        if (open == 0 && close == 0) {
            res.push_back(curr);
            return;
        }

        if (open > 0) {
            generate(open - 1, close, curr + '(', res);
        }

        if (close > open) {
            generate(open, close - 1, curr + ')', res);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generate(n, n, "", res);
        return res;
    }
};


                         "" (3,3)
                          |
                         "(" (2,3)
                       /       \
                 "((" (1,3)     "()" (2,2)
                 /      \           \
           "(((" (0,3)   "(()" (1,2)  "()(" (1,2)
           /       \        \          \
     "((()" (0,2)  "((())" (0,1)     "()()" (0,2)
         \             \               \
      "((()))"      "(()))"         "()()(" (0,1)
                                        \
                                     "()()()" (0,0)
