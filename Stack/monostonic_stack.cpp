#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Insert all the functions from above here...
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// 1. 🔸 Next Greater Element
vector<int> nextGreaterElement(const vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n, -1);
    stack<int> st; // Stack stores indices

    for (int i = 0; i < n; ++i) {
        while (!st.empty() && nums[i] > nums[st.top()]) {
            res[st.top()] = nums[i];
            st.pop();
        }
        st.push(i);
    }

    return res;
}

// 2. 🔸 Previous Greater Element
vector<int> previousGreaterElement(const vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n, -1);
    stack<int> st; // Stack stores indices

    for (int i = 0; i < n; ++i) {
        while (!st.empty() && nums[st.top()] <= nums[i]) {
            st.pop();
        }

        if (!st.empty()) res[i] = nums[st.top()];
        st.push(i);
    }

    return res;
}

// 3. 🔸 Next Smaller Element — ✅ Corrected version (Right to Left)
vector<int> nextSmallerElement(const vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n, -1);
    stack<int> st; // Stack stores actual values

    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && st.top() >= nums[i]) {
            st.pop();
        }

        if (!st.empty()) res[i] = st.top();
        st.push(nums[i]);
    }

    return res;
}

// 4. 🔸 Previous Smaller Element
vector<int> previousSmallerElement(const vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n, -1);
    stack<int> st; // Stack stores indices

    for (int i = 0; i < n; ++i) {
        while (!st.empty() && nums[st.top()] >= nums[i]) {
            st.pop();
        }

        if (!st.empty()) res[i] = nums[st.top()];
        st.push(i);
    }

    return res;

}

void printVector(const string& label, const vector<int>& v) {
    cout << label << ": ";
    for (int x : v) cout << x << " ";
    cout << endl;
}

int main() {
    vector<int> nums = {3, 1, 4, 1, 5, 9, 2, 6};

    auto nge = nextGreaterElement(nums);
    auto pge = previousGreaterElement(nums);
    auto nse = nextSmallerElement(nums);
    auto pse = previousSmallerElement(nums);

    printVector("Next Greater     ", nge);
    printVector("Previous Greater ", pge);
    printVector("Next Smaller     ", nse);
    printVector("Previous Smaller ", pse);

    return 0;
}