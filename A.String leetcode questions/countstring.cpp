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
