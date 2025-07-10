https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1

class Solution {
  public:
    int maxLength(vector<int>& arr) {
        unordered_map<int, int>mpp;
        int maxi =0;
        int presum = 0;
        
        for(int i =0; i<arr.size(); i++){
            presum += arr[i];
            if(presum==0){
                maxi = i+1;
            }
            else{
                if(mpp.find(presum)!= mpp.end()){
                    maxi = max(maxi, i-mpp[presum]);
                }
                else{
                    mpp[presum]= i;
                }
            }
        }
        
        return maxi;
    }
};


//brute force approach
class Solution {
  public:
    int maxLength(vector<int>& arr) {
        int maxLength = 0;
        
        for(int i=0; i<arr.size(); i++){
            int sum =0;
            int count =0;
            for(int j = i; j<arr.size(); j++){
                sum+=arr[j];
                count++;
                if(sum == 0 ){
                maxLength = max(maxLength, count);
                }
            }
            
        }
        return maxLength;
    }
};