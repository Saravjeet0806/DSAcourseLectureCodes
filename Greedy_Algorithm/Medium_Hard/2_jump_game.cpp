class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int maxIndex = 0;
        for (int i = 0; i < nums.size(); i++)
        {

            if (i > maxIndex)
            {
                return false; // we can never reach end
            }

            maxIndex = max(maxIndex, i + nums[i]); // at i = 4 , 4>maxIndex(3) therefore output is false
        }
        return true;
    }
};