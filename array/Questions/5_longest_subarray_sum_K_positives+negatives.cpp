https://takeuforward.org/arrays/longest-subarray-with-sum-k-postives-and-negatives/
https://takeuforward.org/data-structure/longest-subarray-with-given-sum-k/

class Solution {
public:
    int longestSubarray(vector<int>& arr, int k) {
        unordered_map<int, int> prefixSumIndex;
        int sum = 0, maxLen = 0;

        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];

            if (sum == k) {
                maxLen = i + 1; // from index 0 to i
            }

            // Check if there is a prefix sum that satisfies the condition
            if (prefixSumIndex.find(sum - k) != prefixSumIndex.end()) {
                maxLen = max(maxLen, i - prefixSumIndex[sum - k]);
            }

            // Store first occurrence of this sum
            if (prefixSumIndex.find(sum) == prefixSumIndex.end()) {
                prefixSumIndex[sum] = i;
            }
        }

        return maxLen;
    }
};
