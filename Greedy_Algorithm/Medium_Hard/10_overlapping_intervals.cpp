class Solution {
public:
    bool static comp(vector<int>&a, vector<int>&b){
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
       sort(intervals.begin(), intervals.end(), comp); //sort according to interval[i][1]///
       int n = intervals.size();
       int cnt=1;
       int last_end= intervals[0][1];

       for(int i=1; i<n; i++){
        if(intervals[i][0]>=last_end){
            cnt++;
            last_end= intervals[i][1];
        }
       }
       return n-cnt;
    }
};