https : // www.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1

        class Solution
{
public:
    int upperBound(vector<int> &arr, int x, int n)
    {
        int low = 0, high = n - 1;
        int ans = n;

        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (arr[mid] > x)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }

    int countSmallEqual(vector<vector<int>> &matrix, int rows, int cols, int x)
    {
        int cnt = 0;
        for (int i = 0; i < rows; i++)
        {
            cnt += upperBound(matrix[i], x, cols); // upper bound for every row is added
        }
        return cnt;
    }

    int median(vector<vector<int>> &mat)
    {
        int rows = mat.size();
        int cols = mat[0].size();

        int low = INT_MAX, high = INT_MIN;

        for (int i = 0; i < rows; i++)
        {
            low = min(low, mat[i][0]);
            high = max(high, mat[i][cols - 1]);
        }

        int req = (rows * cols) / 2;

        while (low <= high)
        {
            int mid = (low + high) / 2;
            int smallEqual = countSmallEqual(mat, rows, cols, mid);

            if (smallEqual <= req)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return low;
    }
};
