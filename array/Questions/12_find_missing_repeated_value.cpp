class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& nums) {
        //using sets
        int n = nums.size();
        set<int>ans;
        for(int i=1; i<=n*n; i++){
            ans.insert(i);
        }
        int dup=0;
        int miss=0;
        for(int i=0; i<nums.size(); i++){
            for(int j=0; j<nums[i].size(); j++){
                if(ans.find(nums[i][j])!=ans.end()){
                    ans.erase(nums[i][j]);
                }
                else{
                    if(dup==0){
                        dup=nums[i][j];
                    }
                }
            }
        }
        for(auto i: ans){
            miss=i;
        }
        return {dup, miss};
    }
};

//optimal solution
#include <iostream>
#include <vector>
using namespace std;

vector<int> findTwoElement(vector<int>& arr) {
    int n = arr.size();

    // Sum of first n natural numbers
    long long  s = (n * (n + 1)) / 2;
    // Sum of squares of first n natural numbers
    int ssq = (n * (n + 1) * (2 * n + 1)) / 6;

    // Subtract actual values from expected sums
    for (int i = 0; i < n; i++) {
        s -= arr[i];
        ssq -= arr[i] * arr[i];
    }

    // Using the equations: missing - repeating = s
    // missing^2 - repeating^2 = ssq
    int missing = (s + ssq / s) / 2;
    int repeating = missing - s;

    return {repeating, missing};
}

int main() {
    vector<int> arr = {3, 1, 3};
    vector<int> ans = findTwoElement(arr);

    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}