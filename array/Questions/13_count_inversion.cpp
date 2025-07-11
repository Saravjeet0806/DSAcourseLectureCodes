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

