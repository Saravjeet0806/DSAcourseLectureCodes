class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
       int n = deadline.size();
       
       vector<pair<int, int>>jobs(n);
       
       for(int i=0; i<n; i++){
           jobs[i]={profit[i], deadline[i]};
    
       }
       
       sort(jobs.rbegin(), jobs.rend());
       
       int maxDeadline=0;
       for( i : jobs){
           maxDeadline = max(maxDeadline, i.second);
       }
       
       vector<int> slot(maxDeadline+1, -1);
       int count =0, totalProfit =0;
       
       for(int i=0; i<n; i++){
           int d = jobs[i].second;
           int p = jobs[i].first;
           
           for(int j =d; j>=1; j--){
               if(slot[j]==-1){
                   slot[j]=i;
                   count++;
                   totalProfit+=p;
                   break;
               }
           }
       }
       return {count, totalProfit};
        
    }
};