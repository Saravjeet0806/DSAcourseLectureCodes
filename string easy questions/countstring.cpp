https://www.geeksforgeeks.org/problems/count-substring/1

class Solution {
  public:
    int countSubstring(string s) {
        int n = s.length();
        int count[3] = {0}; // count of 'a', 'b', 'c'
        int res = 0;
        int start = 0;

        for (int end = 0; end < n; end++) {
            count[s[end] - 'a']++;

            while (count[0] > 0 && count[1] > 0 && count[2] > 0) {
                // all three characters are present
                res += (n - end); // all substrings from s[start..end] to s[start..n-1] are valid
                count[s[start] - 'a']--;
                start++;
            }
        }

        return res;
    }
};

//The substrings that contributed are:

// From start = 0 to end = 2 → "abc", "abca", "abcab", "abcabc" → 4

// From start = 1 to end = 3 → "bca", "bcab", "bcabc" → 3

// From start = 2 to end = 4 → "cab", "cabc" → 2

// From start = 3 to end = 5 → "abc" → 1
// Total = 4 + 3 + 2 + 1 = 10
