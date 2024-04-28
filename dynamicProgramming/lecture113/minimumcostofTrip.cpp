int solve(int n, vector<int> days, vector<int> cost, int index)
{
    // base case
    if (index >= n)
        return 0;
    // 1day
    int op1 = cost[0] + solve(n, days, cost, index + 1);
    int i;
    // 7days
    for (i = index; i < n && days[i] < days[index] + 7; i++)
        ;
    int op2 = cost[1] + solve(n, days, cost, i);
    // 30days
    for (i = index; i < n && days[i] < days[index] + 30; i++)
        ;
    int op3 = cost[2] + solve(n, days, cost, i);
    return min(op1, min(op2, op3));
}

int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    return solve(n, days, cost, 0);
}

// recursion + memoization solution
int solve(int n, vector<int> days, vector<int> cost, int index, vector<int> &dp)
{
    // base case
    if (index >= n)
        return 0;

    if (dp[index] != -1)
        return dp[index];
    // 1day
    int op1 = cost[0] + solve(n, days, cost, index + 1, dp);
    int i;
    // 7days
    for (i = index; i < n && days[i] < days[index] + 7; i++)
        ;
    int op2 = cost[1] + solve(n, days, cost, i, dp);
    // 30days
    for (i = index; i < n && days[i] < days[index] + 30; i++)
        ;
    int op3 = cost[2] + solve(n, days, cost, i, dp);
    dp[index] = min(op1, min(op2, op3));
    return dp[index];
}

int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    vector<int> dp(n + 1, -1);
    return solve(n, days, cost, 0, dp);
}

// tabulation approach
int solve(int n, vector<int> &days, vector<int> &cost)
{
    // base case
    vector<int> dp(n + 1, INT_MAX);
    dp[n] = 0;

    for (int k = n - 1; k >= 0; k--)
    {
        ;
        // 1day
        int op1 = cost[0] + dp[k + 1];
        int i;
        // 7days
        for (i = k; i < n && days[i] < days[k] + 7; i++)
            ;
        int op2 = cost[1] + dp[i];
        // 30days
        for (i = k; i < n && days[i] < days[k] + 30; i++)
            ;
        int op3 = cost[2] + dp[i];
        dp[k] = min(op1, min(op2, op3));
    }
    return dp[0];
}

int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    return solve(n, days, cost);
}

