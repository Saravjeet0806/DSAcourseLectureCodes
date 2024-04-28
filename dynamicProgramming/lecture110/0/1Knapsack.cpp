// recursive solution
#include <bits/stdc++.h>
int solve(vector<int> weight, vector<int> value, int index, int capacity)
{
    // base case
    // if only one think to steal compare its weight with knapsack capacity
    if (index == 0)
    {
        if (weight[0] <= capacity)
            return value[0];
        else
            return 0;
    }

    int include = 0;
    if (weight[index] <= capacity)
        include = value[index] + solve(weight, value, index - 1, capacity - weight[index]);

    int exclude = 0 + solve(weight, value, index - 1, capacity);

    int ans = max(include, exclude);
    return ans;
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    return solve(weight, value, n - 1, maxWeight); // starting from last index;
}

//recursion +memoization
#include <bits/stdc++.h> 
int solveMem(vector<int> &weight, vector<int>& value, int index, int capacity, vector<vector<int>>&dp){
	//base case
	//if only one think to steal compare its weight with knapsack capacity
        if (index == 0) {
          if (weight[0] <= capacity)
            return value[0];
          else
            return 0;
        }
        if(dp[index][capacity]!=-1)
		return dp[index][capacity];
		int include=0;
		if(weight[index]<=capacity)
        include=value[index]+ solveMem(weight, value, index-1, capacity-weight[index], dp);
		
		int exclude=0 + solveMem(weight, value, index-1, capacity, dp);

		dp[index][capacity]=max(include, exclude);  //2d dp because value and capacity are changing 
		return dp[index][capacity];
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>>dp(n, vector<int>(maxWeight+1, -1)); 
	return solveMem(weight, value, n-1, maxWeight, dp);
}