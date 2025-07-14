https://www.geeksforgeeks.org/problems/row-with-max-1s0023/1

// User function template for C++
class Solution {
  public:
    int lowerbound(vector<int>arr, int col, int num){
        int l=0, h=col-1;
        int ans=col;
        
        while(l<=h){
            int mid = (l+h)/2;
            if(arr[mid]>=num){
                ans=mid;
                h = mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
        
    }
    int rowWithMax1s(vector<vector<int>> &arr) {
        int m = arr[0].size(); //cols
        int n = arr.size(); //rows
         int cnt_max =0;
        int index=-1;
        
        for(int i=0; i<n; i++){
            int cnt = m-lowerbound(arr[i], m, 1);
            if(cnt>cnt_max){
                cnt_max=cnt;
                index=i;
            }
            
        }
        return index;  //row with max 1s
        
    }
};