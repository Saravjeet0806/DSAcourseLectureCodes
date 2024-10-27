class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0, r=0, sumCurr=0;
        int ans=INT_MAX;

        for(r=0; r<nums.size(); r++){
            sumCurr+=nums[r];
            while(sumCurr>=target){
                ans=min(ans, r-l+1);
                sumCurr-=nums[l];
                l++;
            }
        }
        return ans ==INT_MAX? 0 : ans;
    }
};