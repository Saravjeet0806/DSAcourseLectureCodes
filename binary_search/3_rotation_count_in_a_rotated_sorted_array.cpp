https://www.geeksforgeeks.org/problems/rotation4723/1

class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        int n =arr.size();
        int l = 0;
        int h = n-1;
        int ans = INT_MAX;
        int index = -1;
        while(l<=h){
            int mid = (l+h)/2;
            
            if(arr[l]<=arr[h]){  //if full array is sorted
                if(arr[l]<ans){
                    ans = arr[l];
                    index = l;
                }
                break;
            }
            
            if(arr[l]<=arr[mid]){ //if left half is sorted
               if(arr[l]<ans){
                   ans = arr[l];
                   index = l;
               } 
               l=mid+1;
            }
            
            else{  //if right half is sorted
                if(arr[mid]<arr[h]){
                    ans=arr[mid];
                    index = mid;
                }
                h=mid-1;
            }
        }
        return index;
        
    }
};
