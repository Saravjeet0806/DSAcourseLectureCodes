https://www.geeksforgeeks.org/problems/aggressive-cows/1

class Solution
{
public:
    bool canWePlace(vector<int> &stalls, int dist, int cows)
    {
        int n = stalls.size(); // size of array
        int cntCows = 1;       // no. of cows placed
        int last = stalls[0];  // position of last placed cow.
        for (int i = 1; i < n; i++)
        {
            if (stalls[i] - last >= dist)
            {
                cntCows++;        // place next cow.
                last = stalls[i]; // update the last location.
            }
            if (cntCows >= cows)
                return true;
        }
        return false;
    }
    int aggressiveCows(vector<int> &stalls, int k)
    {
        sort(stalls.begin(), stalls.end());
        int l = 1;
        int h = stalls[stalls.size() - 1];

        while (l <= h)
        {
            int mid = (l + h) / 2;
            if (canWePlace(stalls, mid, k) == true)
            {
                l = mid + 1; // if we can place try bigger number
            }
            else
                h = mid - 1;
        }
        return h;
    }
};