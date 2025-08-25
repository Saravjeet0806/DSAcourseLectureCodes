//https://www.geeksforgeeks.org/problems/longest-bitonic-subsequence0824/1 
//lds gfg

class Solution {
public:
    int LongestBitonicSequence(int n, vector<int> &arr) {
        vector<int> dp1(n, 1); // LIS ending at i
        vector<int> dp2(n, 1); // LDS starting at i

        // Longest Increasing Subsequence (LIS)
        for (int i = 0; i < n; i++) {
            for (int prev = 0; prev < i; prev++) {
                if (arr[prev] < arr[i]) {
                    dp1[i] = max(dp1[i], 1 + dp1[prev]);
                }
            }
        }

        // Longest Decreasing Subsequence (LDS)
        for (int i = n - 1; i >= 0; i--) {
            for (int next = n - 1; next > i; next--) {
                if (arr[next] < arr[i]) {
                    dp2[i] = max(dp2[i], 1 + dp2[next]);
                }
            }
        }

        int maxi = 0;
        for (int i = 0; i < n; i++) {
            if (dp1[i] > 1 && dp2[i] > 1) { // valid bitonic
                maxi = max(maxi, dp1[i] + dp2[i] - 1);
            }
        }

        return maxi;
    }
};

