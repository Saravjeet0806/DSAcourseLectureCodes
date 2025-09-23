class Solution {
public:
    int dp[2001][4001];
    int solve(int reward, int index, vector<int>&rewardValues){
        if(index>=rewardValues.size()){
            return reward;
        }
         
        if(dp[index][reward]!=-1) return dp[index][reward];
        int notPick = solve(reward, index+1, rewardValues);
        int pick =0;
        if(rewardValues[index]>reward){
            pick = solve(reward+rewardValues[index], index+1, rewardValues);
        }
         return dp[index][reward] = max(pick, notPick);
    }
    int maxTotalReward(vector<int>& rewardValues) {
        sort(rewardValues.begin(), rewardValues.end());
        int n = rewardValues.size();
        memset(dp,-1,sizeof(dp));

        return solve(0, 0, rewardValues);

    }
};