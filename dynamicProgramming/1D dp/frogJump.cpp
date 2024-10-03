class Solution {
  private:
     int solve(int index, vector<int>&a, vector<int>&dp){
         if(index==0){
             return 0;
         }
         if(dp[index]!=-1){
             return dp[index];
         }
         int left= solve(index-1, a, dp) + abs(a[index]-a[index-1]);
         int right=INT_MAX;
         if(index>1){
             right = solve(index-2, a, dp) + abs(a[index]- a[index-2]);
         }
         return dp[index]= min(left, right);
     }
  public:
    int minimumEnergy(vector<int>& height, int n) {
        vector<int>dp(n+1, -1);
        return solve(n-1, height ,dp);
    }
};

//using tabulation

class Solution {
  private:
     int solve(int index, vector<int>&a, vector<int>&dp){
         if(index==0){
             return 0;
         }
         if(dp[index]!=-1){
             return dp[index];
         }
         int left= solve(index-1, a, dp) + abs(a[index]-a[index-1]);
         int right=INT_MAX;
         if(index>1){
             right = solve(index-2, a, dp) + abs(a[index]- a[index-2]);
         }
         return dp[index]= min(left, right);
     }
  public:
    int minimumEnergy(vector<int>& height, int n) {
        vector<int>dp(n+1, -1);
        return solve(n-1, height ,dp);
    }
};