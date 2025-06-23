//recursion
int rob(vector<int>& nums) {
    if (nums.size() == 1) return nums[0];
    return max(solve(nums, 0, nums.size()-2), solve(nums, 1, nums.size()-1));
}

//top down 

int solve(vector<int>& nums, int start, int end, vector<int>& dp) {
    if(start > end) return 0;
    if(dp[start] != -1) return dp[start];

    return dp[start] = max(nums[start] + solve(nums, start+2, end, dp), solve(nums, start+1, end, dp));
}

int rob(vector<int>& nums) {
    int n = nums.size();
    if(n == 1) return nums[0];
    
    vector<int> dp1(n, -1), dp2(n, -1);
    int ans1 = solve(nums, 0, n-2, dp1);
    int ans2 = solve(nums, 1, n-1, dp2);
    
    return max(ans1, ans2);
}

//bottom up 
int solve(vector<int>& nums, int start, int end) {
    int n = end - start + 1;
    vector<int> dp(n, 0);
    
    dp[0] = nums[start]; // first element is nums[start]
    
    for(int i = 1; i < n; i++) {
        int incl = nums[start + i] + (i > 1 ? dp[i-2] : 0); // pick
        int excl = dp[i-1];                                // not pick
        dp[i] = max(incl, excl);
    }
    
    return dp[n-1];
}

int rob(vector<int>& nums) {
    int n = nums.size();
    if(n == 1) return nums[0];
    
    return max(solve(nums, 0, n-2), solve(nums, 1, n-1));
}


//optimized approach

int solve(vector<int>& nums){
    int prev2 = 0, prev1 = nums[0];
    for(int i=1; i<nums.size(); i++){
        int incl = prev2 + nums[i];
        int excl = prev1;
        int ans = max(incl, excl);
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}

int rob(vector<int>& nums) {
    int n = nums.size();
    if(n == 1) return nums[0];
    
    vector<int> first(nums.begin(), nums.end()-1);
    vector<int> second(nums.begin()+1, nums.end());
    
    return max(solve(first), solve(second));
}
