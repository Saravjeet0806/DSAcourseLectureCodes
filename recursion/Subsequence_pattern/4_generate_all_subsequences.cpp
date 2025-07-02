#include <bits/stdc++.h>
using namespace std;

void findSubsequences(int index, vector<int> &arr,
                      vector<int> &subarr, vector<vector<int>> &res)
{

    // Base case: When we reach the end of the array,
    // add the current subsequence to the result
    if (index == arr.size())
    {
        res.push_back(subarr);
        return;
    }

    //  Include the current element in the subsequence
    subarr.push_back(arr[index]);

    // Recurse to the next element
    findSubsequences(index + 1, arr, subarr, res);

    // Backtrack: Remove the current element and explore
    // the next possibility
    subarr.pop_back();

    //  Do not include the current element
    // in the subsequence
    findSubsequences(index + 1, arr, subarr, res);
}

int main()
{
    vector<int> arr = {1, 2, 3};
    int n = arr.size();

    vector<int> subarr;
    vector<vector<int>> res;

    findSubsequences(0, arr, subarr, res);

    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}