https://www.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1

class Solution {
public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        int m = a.size(), n = b.size();

        // Ensure binary search on the smaller array
        if (m > n) return kthElement(b, a, k);

        int left = k;
        int low = max(0, k - n), high = min(k, m);

        while (low <= high) {
            int mid1 = (low + high) / 2;
            int mid2 = left - mid1;

            // Fetch values using your preferred style
            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;

            if (mid1 < m) r1 = a[mid1];
            if (mid2 < n) r2 = b[mid2];
            if (mid1 - 1 >= 0) l1 = a[mid1 - 1];
            if (mid2 - 1 >= 0) l2 = b[mid2 - 1];

            // Valid partition found
            if (l1 <= r2 && l2 <= r1) {
                return max(l1, l2);
            }

            // Adjust binary search
            else if (l1 > r2) {
                high = mid1 - 1;
            } else {
                low = mid1 + 1;
            }
        }

        return -1; // unreachable if input is valid
    }
};
