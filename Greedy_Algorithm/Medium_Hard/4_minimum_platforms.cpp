// https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1

class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        // Your code here
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        
        int l=0, r=0;
        int count=0;
        int n = arr.size();
        int ans=0;
        
        while(l<n){
            if(arr[l]<=dep[r]){
                count++;
                ans=max(ans, count);
                l++;
            }
            else if(arr[l]>dep[r]){
                count--;
                r++;
            }
        }
        return ans;
    }
};
