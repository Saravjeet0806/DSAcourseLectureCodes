// https://www.naukri.com/code360/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494?leftPanelTabValue=PROBLEM

//bottom up
int minSubsetSumDifference(vector<int>& nums, int n)
{
	
        int totsum = 0;
        for(int i = 0; i < n; i++) totsum += nums[i];

        vector<vector<bool>> dp(n, vector<bool>(totsum + 1, false));
        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }

        if (nums[0] <= totsum) {
            dp[0][nums[0]] = true;
        }

        for (int ind = 1; ind < n; ind++) {
            for (int j = 0; j <= totsum; j++) {
                bool notTaken = dp[ind - 1][j];
                bool taken = false;
                if (nums[ind] <= j) {
                    taken = dp[ind - 1][j - nums[ind]];
                }
                dp[ind][j] = notTaken || taken;
            }
        }

        int mini = INT_MAX;
        for (int s1 = 0; s1 <= totsum / 2; s1++) {
            if (dp[n - 1][s1]) {
                mini = min(mini, abs((totsum - s1) - s1));
            }
        }
        return mini;

}

//space optimization

int minSubsetSumDifference(vector<int>& nums, int n)
{
	if (nums.empty()) return 0; // ?? Prevents nums[0] access if empty

        int totsum = accumulate(nums.begin(), nums.end(), 0);
        int target = totsum / 2;
        

        vector<bool> prev(target + 1, false);
        prev[0] = true;

        if (nums[0] <= target) {
            prev[nums[0]] = true;
        }

        for (int ind = 1; ind < n; ind++) {
            vector<bool> curr(target + 1, false);
            curr[0] = true;

            for (int j = 1; j <= target; j++) {
                bool notTaken = prev[j];
                bool taken = false;
                if (nums[ind] <= j) {
                    taken = prev[j - nums[ind]];
                }
                curr[j] = notTaken || taken;
            }

            prev = curr;
        }

        int mini = INT_MAX;
        for (int s1 = 0; s1 <= target; s1++) {
            if (prev[s1]) {
                int s2 = totsum - s1;
                mini = min(mini, abs(s2 - s1));
            }
        }

        return mini;
}
