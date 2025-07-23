class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorAll = 0;
        // Step 1: XOR everything to get xorAll = A ^ B
        for (int num : nums) {
            xorAll ^= num;
        }

        // Step 2: Find any set bit in xorAll (rightmost is easy)
        int diffBit = xorAll & (-xorAll);  // Isolates rightmost set bit

        int num1 = 0, num2 = 0;
        // Step 3: Partition numbers into two groups by this bit, and XOR separately
        for (int num : nums) {
            if (num & diffBit) 
                num1 ^= num; // Group with the bit set
            else
                num2 ^= num; // Group with the bit not set
        }
        return {num1, num2};
    }
};

//
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorAll = 0;
        // Step 1: XOR all elements => xorAll = A ^ B
        for (int num : nums) {
            xorAll ^= num;
        }

        // Step 2: Get the rightmost set bit in xorAll
        unsigned int diffBit = xorAll & (-(unsigned int)xorAll);


        int num1 = 0, num2 = 0;
        // Step 3: Divide into two groups based on the diffBit and XOR within each
        for (int num : nums) {
            if (num & diffBit)
                num1 ^= num;  // Group where bit is set
            else
                num2 ^= num;  // Group where bit is not set
        }

        return {num1, num2};
    }
};