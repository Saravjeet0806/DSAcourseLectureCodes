class Solution {
  public:
    int count(vector<int>arr, int pages){
        int n = arr.size();
        int students =1;
        long long pagesStudent= 0;
        for(int i =0; i<n; i++){
            if(pagesStudent+arr[i]<=pages){
                pagesStudent+=arr[i];
            }
            else{
                students++;
                pagesStudent=arr[i];
            }
        }
        return students;
    }
    int findPages(vector<int> &arr, int k) {
        int n = arr.size();
        if(k>n) return -1;
        int l = *max_element(arr.begin(), arr.end());
        int h = accumulate(arr.begin(), arr.end(), 0);
        
        while(l<=h){
            int mid = (l+h)/2;
            int students = count(arr, mid);
            if(students>k){
                l=mid+1;
            }
            else{
                h= mid-1;
            }
        }
        return l;
    }
};