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