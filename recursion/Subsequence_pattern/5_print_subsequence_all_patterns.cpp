#include <iostream>
#include <vector>
using namespace std;

// Function to print all subsequences with sum == k
void printSubsequencesWithSumK(int index, vector<int> &arr, int sum, int k, vector<int> &current) {
    if (index == arr.size()) {
        if (sum == k) {
            for (int val : current) cout << val << " ";
            cout << endl;
        }
        return;
    }

    // Pick the current element
    current.push_back(arr[index]);
    printSubsequencesWithSumK(index + 1, arr, sum + arr[index], k, current);

    // Not pick the current element
    current.pop_back();
    printSubsequencesWithSumK(index + 1, arr, sum, k, current);
}

// Function to check if any subsequence has sum == k
bool hasSubsequenceWithSumK(int index, vector<int> &arr, int sum, int k) {
    if (index == arr.size()) {
        return sum == k;
    }

    // Pick
    if (hasSubsequenceWithSumK(index + 1, arr, sum + arr[index], k)) return true;

    // Not pick
    if (hasSubsequenceWithSumK(index + 1, arr, sum, k)) return true;

    return false;
}

int main() {
    vector<int> arr = {1, 2, 1};
    int k = 2;

    cout << "Subsequences with sum " << k << ":\n";
    vector<int> current;
    printSubsequencesWithSumK(0, arr, 0, k, current);

    cout << "\nIs there any subsequence with sum " << k << "? ";
    if (hasSubsequenceWithSumK(0, arr, 0, k))
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}
