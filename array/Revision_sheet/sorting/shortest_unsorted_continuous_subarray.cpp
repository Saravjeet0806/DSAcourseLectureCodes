class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
      // use test case 4, 6, 1, 2, 5, 8, 3, 7 .. //edge case
      int i=0, j= nums.size()-1;
      while(i+1<nums.size() && nums[i+1]>=nums[i]) i++;
      while(j-1>=0 && nums[j]>=nums[j-1]) j--;

      if(i==nums.size()-1) return 0;

      int mini=INT_MAX, maxi=INT_MIN;
      for(int k=i; k<=j; k++){
         mini = min(mini, nums[k]);
         maxi = max(maxi, nums[k]);
      }

      while(i-1>=0 && nums[i-1]>mini) i--;
      while(j+1<=nums.size()-1 && nums[j+1]<maxi) j++;

      return j-i+1;
        
    }
};