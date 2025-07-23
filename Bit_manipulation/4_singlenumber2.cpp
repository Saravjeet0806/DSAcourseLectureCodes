class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        // Iterate over each bit position (32 bits for int)
        for (int i = 0; i < 32; i++) {
            int bitCount = 0;
            // Count how many numbers have the i-th bit set
            for (int num : nums) {
                if (num & (1 << i))
                    bitCount++;
            }
            // If bitCount % 3 == 1, this bit belongs to the unique number
            if (bitCount % 3) {
                // Set the i-th bit in the result
                result |= (1 << i);
            }
        }
        return result;
    }
};
