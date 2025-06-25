// https://www.naukri.com/code360/problems/count-subsets-with-sum-k_3952532?leftPanelTabValue=SUBMISSION

// recursive
int count(int ind, int k, vector<int> &arr)
{
    if (k == 0)
        return 1;
    if (ind == 0)
        return (arr[ind] == k);

    int notpick = count(ind - 1, k, arr);
    int pick = 0;
    if (arr[ind] <= k)
    {
        pick = count(ind - 1, k - arr[ind], arr);
    }
    return notpick + pick;
}

int findWays(vector<int> &arr, int k)
{
    int n = arr.size();
    return count(n - 1, k, arr);
}

// memoization top down
int count(int ind, int k, vector<int> &arr, vector<vector<int>> &dp)
{
    if (k == 0)
        return 1;
    if (ind == 0)
        return (arr[ind] == k);
    if (dp[ind][k] != -1)
    {
        return dp[ind][k];
    }
    int notpick = count(ind - 1, k, arr, dp);
    int pick = 0;
    if (arr[ind] <= k)
    {
        pick = count(ind - 1, k - arr[ind], arr, dp);
    }
    dp[ind][k] = notpick + pick;
    return dp[ind][k];
}

int findWays(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return count(n - 1, k, arr, dp);
}

// tabulation bottom up
int findWays(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(k + 1, 0));
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 1;
    }

    if (arr[0] <= k)
        dp[0][arr[0]] = 1;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            int notpick = dp[i - 1][j];
            int pick = 0;
            if (arr[i] <= j)
                pick = dp[i - 1][j - arr[i]];
            dp[i][j] = notpick + pick;
        }
    }
    return dp[n - 1][k];
}
// use modulus if all the test cases are not passing

int mod = 1e9 + 7;

int helper(int i, int k, vector<int> &ar, vector<vector<int>> &dp)
{

    if (i == 0)
    {
        if (k == 0 && ar[0] == 0) //imp
            return 2;
        if (k == ar[i] || k == 0)
            return 1;
        else
            return 0;
    }

    if (dp[i][k] != -1)
        return dp[i][k];

    int notpick = helper(i - 1, k, ar, dp);

    int pick = 0;

    if (ar[i] <= k)
        pick = helper(i - 1, k - ar[i], ar, dp);

    return dp[i][k] = (notpick + pick) % mod;
}

int findWays(vector<int> &arr, int k)

{

    int n = arr.size();

    vector<vector<int>> dp(n, vector<int>(k + 1, -1));

    return helper(arr.size() - 1, k, arr, dp);
}
