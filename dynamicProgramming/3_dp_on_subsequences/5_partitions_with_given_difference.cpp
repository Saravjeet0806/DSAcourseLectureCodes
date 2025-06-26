//https://www.naukri.com/code360/problems/partitions-with-given-difference_3751628

#include <bits/stdc++.h> 

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

int countPartitions(int n, int d, vector<int> &arr) {
   int totsum =0;
   for(int i=0; i<arr.size(); i++) totsum+=arr[i];
   if(totsum-d<0 || ((totsum-d)%2)) return 0;
   return findWays(arr, (totsum-d)/2);
}


