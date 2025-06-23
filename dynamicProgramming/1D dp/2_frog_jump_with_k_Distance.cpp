//  Problem Statement (Generalized Frog Jump):
// You are given an array arr[] of size n, representing the height of stones.

// The frog starts at the first stone (index 0).

// The frog can jump from stone i to any of the next k stones (i+1, i+2, ..., i+k).

// Cost of jumping from stone i to j → abs(arr[i] - arr[j])

// The goal is to reach the last stone (index n-1) with minimum total cost.


// approach 1  //brute force

int f(int i, vector<int>& arr, int k) {
    if (i == 0) return 0;

    int minCost = INT_MAX;
    for (int j = 1; j <= k; j++) {
        if (i - j >= 0)
            minCost = min(minCost, f(i - j, arr, k) + abs(arr[i] - arr[i - j]));
    }
    return minCost;
}

//memoization + top down
int f(int i, vector<int>& arr, vector<int>& dp, int k) {
    if (i == 0) return 0;
    if (dp[i] != -1) return dp[i];

    int minCost = INT_MAX;
    for (int j = 1; j <= k; j++) {
        if (i - j >= 0)
            minCost = min(minCost, f(i - j, arr, dp, k) + abs(arr[i] - arr[i - j]));
    }
    return dp[i] = minCost;
}

//bottom up + tabulation
class Solution {
 
  public:
    int minimizeCost(int k, vector<int>& arr) {
        int n=arr.size();
        vector<int> dp(n, INT_MAX); 
        dp[0] = 0;  
   
    for (int i = 1; i < n; i++) {
       
        for (int j = 1; j <= k; j++) {
            if (i - j >= 0) {  
                int jumpCost = dp[i - j] + abs(arr[i] - arr[i - j]);
                dp[i] = min(dp[i], jumpCost); 
            }
        }
    }
    
       return dp[n - 1];
    }
};