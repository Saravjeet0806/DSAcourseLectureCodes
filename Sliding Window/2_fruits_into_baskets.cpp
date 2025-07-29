class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> freq;
        int l = 0, r = 0, maxlen = 0;

        while (r < fruits.size()) {
            freq[fruits[r]]++;

            if (freq.size() > 2) {
                freq[fruits[l]]--;
                if (freq[fruits[l]] == 0) {
                    freq.erase(fruits[l]);
                }
                l++;
            }

            // Only update maxlen when window is valid
            maxlen = max(maxlen, r - l + 1);
            r++;
        }
        return maxlen;
    }
};
