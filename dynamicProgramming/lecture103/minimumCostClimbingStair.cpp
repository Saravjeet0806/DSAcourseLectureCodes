class Solution {
public:
int solve(vector<int>&cost, int n, vector<int> & dp){
    //base case
    if(n==0)
    return cost[0];
    if(n==1)
    return cost[1];
    //step3
    if(dp[n]!=-1)
    return dp[n];
     //step 2
    dp[n]=cost[n]+ min(solve(cost, n-1, dp), solve(cost, n-2, dp));
    return dp[n];
}
    int minCostClimbingStairs(vector<int>& cost) {
       int n=cost.size();
       //step 1
       vector<int> dp(n+1, -1);
       int ans= min(solve(cost, n-1, dp), solve(cost, n-2, dp));
       return ans;
    }
};

//using tabulation method
class Solution {
public:
int solve(vector<int>&cost, int n){
    //step1
    vector<int> dp(n+1);
    //step2
    dp[0]=cost[0];
    dp[1]=cost[1];
    //step3
    for(int i=2; i<n; i++){
        dp[i]=min(dp[i-1],dp[i-2])+cost[i];
    }
    return min(dp[n-1], dp[n-2]);
}
    int minCostClimbingStairs(vector<int>& cost) {
       int n=cost.size();
       return solve(cost, n);
    }
};

//using space optimization method

class Solution {
    private: 
    int solve(vector<int>&cost, int N){
        int prev2= cost[0];
        int prev1=cost[1];
        
        for(int i=2; i<N; i++){
            int curr= cost[i]+ min(prev1, prev2);
            prev2=prev1;
            prev1=curr;
        }
     return min(prev1, prev2);   
    }
  public:
  
    int minCostClimbingStairs(vector<int>&cost ,int N) {
      return solve(cost, N);
    }
};