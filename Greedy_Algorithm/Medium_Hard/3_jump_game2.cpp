class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0, currEnd = 0, farthest = 0;
        int n = nums.size();

        for (int i = 0; i < n - 1; i++) {
            farthest = max(farthest, i + nums[i]);
            if (i == currEnd) {
                jumps++;
                currEnd = farthest;
            }
        }

        return jumps;
    }
};



// Iterate from 0 to n-2 (we don’t need to process the last index).

// farthest → keeps the farthest reachable index so far.

// If i == currEnd → we must jump now → increment jumps and set currEnd = farthest.



//  sliding window approach
    int n = nums.size();
        int jumps = 0;
        int l = 0, r = 0;

        while (r < n - 1) {
            int farthest = 0;

            // Explore the current range [l, r] to find the farthest reachable point
            for (int i = l; i <= r; i++) {
                farthest = max(farthest, i + nums[i]);
            }

            // Move to the next window
            l = r + 1;
            r = farthest;
            jumps++;
        }

        return jumps;

