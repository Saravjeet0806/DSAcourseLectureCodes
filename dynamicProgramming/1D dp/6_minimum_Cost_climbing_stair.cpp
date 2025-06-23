class Solution {
public:
    int solve(int index, vector<int> cost, vector<int>&dp){
        if(index==0) return cost[0];
        if(index==1) return cost[1];

        if(dp[index]!=-1) return dp[index];

        dp[index] = cost[index] + min(solve(index-1, cost, dp), solve(index-2, cost, dp));

        return dp[index];

    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1, -1);
        int ans = min(solve(n-1, cost, dp), solve(n-2, cost, dp));
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