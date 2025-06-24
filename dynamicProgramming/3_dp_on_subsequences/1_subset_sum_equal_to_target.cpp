// https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1

// recursion
class Solution
{
public:
    bool f(int ind, int sum, vector<int> arr)
    {
        if (sum == 0)
            return true;
        if (ind == 0)
            return (arr[0] == 0);

        bool notTake = f(ind - 1, sum, arr);
        bool take = false;
        if (arr[ind] <= sum)
            take = f(ind - 1, sum - arr[ind], arr);

        return take | notTake;
    }
    bool isSubsetSum(vector<int> &arr, int sum)
    {
        int n = arr.size();

        return f(n - 1, sum, arr);
    }
};

// memoization
class Solution
{
public:
    bool f(int ind, int sum, vector<int> arr, vector<vector<int>> &dp)
    {
        if (sum == 0)
            return true;
        if (ind == 0)
            return (arr[0] == 0);
        if (dp[ind][sum] != -1)
            return dp[ind][sum];
        bool notTake = f(ind - 1, sum, arr, dp);
        bool take = false;
        if (arr[ind] <= sum)
            take = f(ind - 1, sum - arr[ind], arr, dp);

        return dp[ind][sum] = take | notTake;
    }
    bool isSubsetSum(vector<int> &arr, int sum)
    {

        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));

        return f(n - 1, sum, arr, dp);
    }
};

// bottom up

class Solution
{
public:
    bool isSubsetSum(vector<int> &arr, int sum)
    {
        int n = arr.size();
        vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));

        // Base case: If the target sum is 0, we can always achieve it by taking no elements
        for (int i = 0; i < n; i++)
        {
            dp[i][0] = true;
        }

        // Base case: If the first element of 'arr' is less than or equal to 'sum', set dp[0][arr[0]] to true
        if (arr[0] <= sum)
        {
            dp[0][arr[0]] = true;
        }

        // Fill the DP array iteratively
        for (int ind = 1; ind < n; ind++)
        {
            for (int j = 1; j <= sum; j++)
            {
                // If we don't take the current element, the result is the same as the previous row
                bool notTaken = dp[ind - 1][j];

                // If we take the current element, subtract its value from the target and check the previous row
                bool taken = false;
                if (arr[ind] <= j)
                {
                    taken = dp[ind - 1][j - arr[ind]]; //bottom up
                }

                // Store the result in the DP array for the current subproblem
                dp[ind][j] = notTaken || taken;
            }
        }

        // The final result is stored in dp[n-1][k]
        return dp[n - 1][sum];
    }
};