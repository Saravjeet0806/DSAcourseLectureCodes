class Solution {
private: 
    void solve(vector<int>& nums, vector<int>& output, int index, vector<vector<int>>& ans) {
        // Base case
        if(index >= nums.size()) {
            ans.push_back(output);
            return;
        }
        
        // Include the current element and move to the next
        output.push_back(nums[index]);
        solve(nums, output, index + 1, ans);
        
        // Backtrack to remove the last element before returning
        output.pop_back();

         // Exclude the current element and move to the next
        solve(nums, output, index + 1, ans);
    }    
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        solve(nums, output, 0, ans);
        return ans;
    }
};


// without non empty subset -- codestudio question https://www.naukri.com/code360/problems/find-all-subsets_2041970?leftPanelTabValue=PROBLEM

void solve(int i, vector<int>&ds, vector<vector<int>>&ans, vector<int>arr){
    if(ds.size()==0 && i>=arr.size()){
        return;
    }
    if(i>=arr.size()) {
        ans.push_back(ds);
        return;
    }

    //include
    ds.push_back(arr[i]);
    solve(i+1, ds, ans, arr);
    ds.pop_back(); //back_track
    //exclude
    solve(i+1, ds, ans, arr);
}
vector<vector<int>> FindAllSubsets(vector<int> &arr){
    vector<vector<int>> ans;
    vector<int> ds;
    solve(0, ds, ans, arr);
    return ans;
}