class Solution {
  public:

    int findFloor(vector<int>& arr, int x) {
        // Your code here
         int low = 0;
        int n = arr.size();
        int high = n - 1;
        int ans;
        if(arr[0]>x){
            return -1;
        }
        while (low <= high) {
            int mid = (low+high)/2;
            if (arr[mid] <= x) {
                ans = mid;
               low = mid+1;
            } else {
                high = mid - 1; 
            }
        }
        return ans;
    }
};