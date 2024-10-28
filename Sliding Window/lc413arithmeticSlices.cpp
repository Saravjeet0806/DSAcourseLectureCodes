class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if (n < 3)
            return 0;
        int s = 0, ans = 0;

        while (s < n - 2) {
            int diff = nums[s + 1] - nums[s];
            int e = s + 1;
            while (e < n - 1 && nums[e + 1] - nums[e]) {
                e++;
            }
            int length = e - s + 1;

            if (length >= 3) {
                ans += (length - 2) * (length - 1) / 2;
            }
            s=e;
        }

        return ans;
    }
};