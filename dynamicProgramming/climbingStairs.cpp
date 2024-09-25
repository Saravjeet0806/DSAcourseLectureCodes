class Solution {
public:
    int climbStairs(int n) {
         int prev2 = 1; //base case like
          int prev = 1;
  
      for(int i=2; i<=n; i++){
            int cur_i = prev2+ prev; //ways to reach i (i-1)+(i-2)
             prev2 = prev;
             prev= cur_i;
         }
         return prev;
    }
};