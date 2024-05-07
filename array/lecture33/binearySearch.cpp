//binarySearch using recursion
#include <iostream>
using namespace std;

bool binarySearch(int *arr, int s, int e, int k){
    //base case
    //element not found
    if(s>e)
        return false;
    //base case when element found
     int mid = s+(e-s)/2;
    if(arr[mid]==k){
        return true;
    }
   
    if(arr[mid]<k){
        return binarySearch(arr, mid+1,e,k);
    }
    else{
        return binarySearch(arr, s, mid-1, k);
    }
}

int main(){
int arr[6]={2,4,6,10,14,17};
int key= 18;
int size=6;
cout<<"present or not "<<binarySearch(arr,0,5,key)<<endl;

return 0;
}



// //code studio solutionint solve(vector<int>& nums, int s, int e, int k){
//     //base case
//     //element not found
//     if(s>e)
//         return -1;
//     //base case when element found
//      int mid = s+(e-s)/2;
//     if(nums[mid]==k){
//         return mid;
//     }
   
//     if(nums[mid]<k){
//         return solve(nums, mid+1,e,k);
//     }
//     else{
//         return solve(nums, s, mid-1, k);
//     }
// }
// int search(vector<int>& nums, int target) {
//     int ans=solve(nums, 0, nums.size()-1, target);
// }