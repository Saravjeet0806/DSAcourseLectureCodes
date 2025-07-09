//leetcode solution
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate, count = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (count == 0) candidate = nums[i];
            if (nums[i] == candidate) count++;
            else count--;
        }
        return candidate;
    }
};

//when majority element is not guaranteed
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate, count = 0;
        int n = nums.size();

        // Step 1: Find a potential candidate using Moore's Voting
        for (int i = 0; i < n; i++) {
            if (count == 0) {
                candidate = nums[i];
                count = 1;
            } else if (nums[i] == candidate) {
                count++;
            } else {
                count--;
            }
        }

        // Step 2: Verify the candidate
        int freq = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == candidate) freq++;
        }

        if (freq > n / 2) return candidate;
        return -1;  // No majority element
    }
};
