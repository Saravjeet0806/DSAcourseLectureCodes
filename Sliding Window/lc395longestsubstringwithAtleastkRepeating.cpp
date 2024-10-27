/*Explanation of the Code:
Outer Loop:

We try every possible unique character count in the substring (from 1 to 26).
Sliding Window:

For each uniqueTarget (number of unique characters), we use a sliding window with left and right pointers.
The freq map stores the frequency of characters in the current window.
Expanding the Window:

As we move the right pointer, we add new characters to the frequency map.
If a character’s frequency becomes equal to k, we increment countAtLeastK.
Shrinking the Window:

If the number of unique characters exceeds uniqueTarget, we shrink the window from the left.
Updating the Answer:

If the number of unique characters matches the number of characters with frequency >= k, we update maxLen.

*/

class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.size();
        int maxLen = 0;

        // Try for every possible unique character count (from 1 to 26)
        for (int i = 1; i <= 26; i++) {
            unordered_map<char, int> freq;
            int left = 0, right = 0;
            int unique = 0;        // Number of unique characters in the window
            int countAtLeastK = 0; // Characters with frequency >= k

            // Expand the right end of the window
            while (right < n) {
                char c = s[right];
                right++; // Move the right pointer

                // Update frequency map
                freq[c] = freq[c] + 1;
                if (freq[c] == 1)
                    unique++; // New unique character added
                if (freq[c] == k)
                    countAtLeastK++; // Meets k frequency

                // Shrink the window if unique characters exceed i
                while (unique > i) {
                    char d = s[left];
                    left++; // Move the left pointer

                    // Update frequency map
                    if (freq[d] == k)
                        countAtLeastK--; // No longer meets k frequency
                    freq[d] = freq[d] - 1;
                    if (freq[d] == 0)
                        unique--; // Character removed entirely
                }

                // If all unique characters meet the k frequency condition,
                // update maxLen
                if (unique == countAtLeastK) {
                    maxLen = max(maxLen, right - left);
                }
            }
        }

        return maxLen;
    }
};