https://takeuforward.org/arrays/longest-subarray-with-sum-k-postives-and-negatives/
https://takeuforward.org/data-structure/longest-subarray-with-given-sum-k/

class Solution {
public:
    int longestSubarray(vector<int>& arr, int k) {
        int left = 0, right = 0, sum = 0, maxLen = 0;
        int n = arr.size();

        while (right < n) {
            sum += arr[right];

            while (left <= right && sum > k) {
                sum -= arr[left];
                left++;
            }

            if (sum == k) {
                maxLen = max(maxLen, right - left + 1);
            }

            right++;
        }

        return maxLen;
    }
};
