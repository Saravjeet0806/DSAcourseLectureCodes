https://www.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/1
class Solution
{
public:
    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int> &arr)
    {
        unordered_set<int> st;
        int longest = 1;

        for (auto i : arr)
        {
            st.insert(i);
        }

        for (auto it : st)
        {
            if (st.find(it - 1) == st.end())
            {
                int cnt = 1;
                int x = it;

                while (st.find(x + 1) != st.end())
                {
                    cnt++;
                    x = x + 1;
                }
                longest = max(cnt, longest);
            }
        }
        return longest;
    }
};