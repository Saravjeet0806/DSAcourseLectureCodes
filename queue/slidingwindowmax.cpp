class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        deque<int> q; //contains indexes
        for(int i=0; i<n; i++){
            while(!q.empty() && i-q.front()>=k) //if window size becomes greater than k
               q.pop_front();
            while(!q.empty() && nums[q.back()]<nums[i]) //if greater element comes than pop back
               q.pop_back();
            q.push_back(i); //push index into deque

            if(i>=k-1) ans.push_back(nums[q.front()]);   //This ensures that we only start recording results once the first full window of size k is formed.
        }
        return ans;
    }
};