https://www.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1
class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
       int n = dist.size();
       
       for(int k = 0; k<n; k++){
           for(int i = 0; i<n; i++){
               for(int j=0; j<n; j++){
                   if(dist[i][k]==(int)1e8 || dist[k][j]==(int)1e8)
                   continue;
                   
                   dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
               }
           }
       }
        
    }
};