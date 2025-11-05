//brute force
class Solution {
  public:
    int inversionCount(vector<int> &arr) {
        // Code Here
        int count =0;
        for(int i =0; i<arr.size(); i++){
            for(int j=i+1; j<arr.size(); j++){
                if(arr[j]<arr[i]){
                    count++;
                }
            }
        }
        return count;
    }
};
//optimized approach
#include <bits/stdc++.h> 
int merge(long long *arr,int low,int mid,int high)
{
    vector<int>temp;
    int cnt=0;
    int left=low,right=mid+1;
    while(left<=mid and right<=high)
    {
        if(arr[left]<=arr[right])
        {
          temp.push_back(arr[left]);
          left++;
        }
        else{
            temp.push_back(arr[right]);
              cnt+=mid-left+1;
          right++;
      
        }
    }
    while(left<=mid)
    {
        temp.push_back(arr[left]);
          left++;
    }
    while(right<=high)
    {
        temp.push_back(arr[right]);
          right++;
            
        
    }
    for(int i=low;i<=high;i++)
    {

        arr[i]=temp[i-low];
    }
    return cnt;
}
int mergesort(long long *arr,int low,int high)
{
    int cnt=0;
    if(low>=high)
    return cnt;
    int mid=(low+high)/2;
    cnt+=mergesort(arr, low, mid);
    cnt+=mergesort(arr, mid+1, high);
    cnt+=merge(arr,low,mid,high);
    return cnt;
}
long long getInversions(long long *arr, int n){
    long long cnt=0;
    cnt=mergesort(arr,0,n-1);
    return cnt;
}