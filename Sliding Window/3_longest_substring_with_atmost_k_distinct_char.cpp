https://www.naukri.com/code360/problems/distinct-characters_2221410

#include <unordered_map>
int kDistinctChars(int k, string &str)
{
    unordered_map<char, int> freq;
        int l = 0, r = 0, maxlen = 0;

        while (r < str.size()) {
            freq[str[r]]++;

            if (freq.size() > k) {
                freq[str[l]]--;
                if (freq[str[l]] == 0) {
                    freq.erase(str[l]);
                }
                l++;
            }

            // Only update maxlen when window is valid
            maxlen = max(maxlen, r - l + 1);
            r++;
        }
        return maxlen;
}

