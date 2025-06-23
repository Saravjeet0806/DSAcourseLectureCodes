// brute force

class Solution
{
public:
    int climbStairs(int n)
    {
        if (n == 0 || n == 1)   // it means there are two ways to be here .. if you have 0 steps to climb or 1 step to climb.. there you have one way
            return 1;
        return climbStairs(n - 1) + climbStairs(n - 2);
    }
};

// Recursion + Memoization (Top-Down DP)
//  Optimize recursion by storing results of already solved subproblems.

vector<int> dp;

int climb(int n, vector<int>& dp)
{
    if (n == 0 || n == 1)
        return 1;
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = climb(n - 1, dp) + climb(n - 2, dp);
}

int climbStairs(int n)
{
    vector<int> dp(n + 1, -1);  // Initialize to -1 using constructor
    return climb(n, dp);
}


// bottom up

int climbStairs(int n)
{
    int dp[n + 1];
    dp[0] = dp[1] = 1;

    for (int i = 2; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];

    return dp[n];
}

// final solution
class Solution
{
public:
    int climbStairs(int n)
    {
        int prev2 = 1; // base case like
        int prev = 1;

        for (int i = 2; i <= n; i++)
        {
            int cur_i = prev2 + prev; // ways to reach i (i-1)+(i-2)
            prev2 = prev;
            prev = cur_i;
        }
        return prev;
    }
};