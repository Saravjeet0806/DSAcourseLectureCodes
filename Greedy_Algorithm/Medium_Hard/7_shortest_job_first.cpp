// https://www.geeksforgeeks.org/problems/shortest-job-first/1

class Solution {
  public:
    long long solve(vector<int>& bt) {
       sort(bt.begin(), bt.end());
       
       int time = 0, wt =0;
       for(int i=0; i<bt.size(); i++){
           wt+=time;    
           time+=bt[i];
       }
       
       return (wt/bt.size());
        
    }
};