//https://www.naukri.com/code360/problems/ninja%E2%80%99s-training_3621003

//memoization
class Solution {
  private:
    int f(int day, int last, vector<vector<int>>&arr, vector<vector<int>>&dp){
        if(day==0){
            int maxi =0;
            for(int task =0; task<3; task++){
                if(task!=last){
                maxi=max(maxi, arr[0][task]);
                }
            }
            return maxi;
        }
        
        if(dp[day][last]!=-1){
            return dp[day][last];
        }
        int maxi =0;
        for(int task =0; task<3; task++){
            if(task!=last){
            int point = arr[day][task] + f(day-1, task, arr, dp);
            maxi = max(maxi, point);
            }
        }
        return dp[day][last] = maxi;
    }
  public:
    int maximumPoints(vector<vector<int>>& arr, int n) {
       vector<vector<int>>dp(n, vector<int>(4, -1));
       return f(n-1, 3, arr, dp);
    }
};

//tabulation solution 
class Solution {
  public:
    int maximumPoints(vector<vector<int>>& arr, int n) {
       vector<vector<int>>dp(n, vector<int>(4, -1));
       dp[0][0] = max(arr[0][1], arr[0][2]);
       dp[0][1] = max(arr[0][0], arr[0][2]);
       dp[0][2] = max(arr[0][0], arr[0][1]);
       dp[0][3] = max(arr[0][1], max(arr[0][2], arr[0][2]));
       
       for(int day =1; day<n; day++){
           for(int last=0; last<4; last++){
               dp[day][last]= 0;
               for(int task=0; task<3; task++){
                   if(task!=last){
                       int point = arr[day][task] + dp[day-1][task];
                       dp[day][last] = max(dp[day][last], point);
                   }
               }
           }
       }
       return dp[n-1][3];
    }
};

//space optimization
class Solution {
  public:
    int maximumPoints(vector<vector<int>>& arr, int n) {
       vector<int>prev(4, 0);
       prev[0] = max(arr[0][1], arr[0][2]);
       prev[1]= max(arr[0][0], arr[0][2]);
       prev[2] = max(arr[0][0], arr[0][1]);
       prev[3] = max(arr[0][1], max(arr[0][1], arr[0][2]));
       
       for(int day =1; day<n; day++){
           vector<int>temp(4,0);
           for(int last=0; last<4; last++){
               temp[last]= 0;
               for(int task=0; task<3; task++){
                   if(task!=last){
                       temp[last] = max(temp[last], arr[day][task] + prev[task]);
                   }
               }
           }
           prev = temp;
       }
       return prev[3];
    }
};