// https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1

class Solution {
    
  public:
     bool static comparator(pair<int,int>&a, pair<int,int>&b){
         double r1 = (double)a.first/a.second;
         double r2 = (double)b.first/b.second;
         
         return r1>r2; //sort by value/weightratio in descending order
     }
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        
        vector<pair<int,int>>items;
        for(int i=0; i<n; i++){
            items.push_back({val[i], wt[i]});
        }
        
        sort(items.begin(), items.end(), comparator);
        
        double ans = 0.0;
        
        for(int i=0; i<n; i++){
            if(items[i].second<=capacity){
                capacity-=items[i].second;
                ans+=items[i].first;
            }
            
            else{
                ans+=((double)items[i].first/items[i].second)*capacity;
                break;
            }
        }
        return ans;
    }
};
