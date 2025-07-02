#include <iostream>
#include <vector>
using namespace std;

void generatePowerSet(const vector<int>& nums) {
    int n = nums.size();
    int totalSubsets = 1 << n;  // 2^n subsets

    for (int mask = 0; mask < totalSubsets; ++mask) {
        vector<int> subset;
        for (int i = 0; i < n; ++i) {
            // Check if the ith bit is set in mask
            if (mask & (1 << i)) {
                subset.push_back(nums[i]);
            }
        }

        // Print the subset
        cout << "{ ";
        for (int val : subset) {
            cout << val << " ";
        }
        cout << "}" << endl;
    }
}

int main() {
    vector<int> nums = {1, 2, 3};
    generatePowerSet(nums);
    return 0;
}
