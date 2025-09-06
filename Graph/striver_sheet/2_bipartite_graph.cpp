https://www.geeksforgeeks.org/problems/bipartite-graph/1
//bfs
class Solution {
  public:
    bool check(int start, int V, vector<vector<int>>adj, int color[]){
        queue<int>q;
        q.push(start);
        color[start]=0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto it : adj[node]){
                if(color[it]==-1){
                    color[it] = !color[node];
                    q.push(it);
                }
                //is the adjacent node having the same color // someone colored same from some other path
                else if(color[it]==color[node]){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(int V, vector<vector<int>> &edges) {
        vector<vector<int>>adj(V);
        
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
       int color[V];
       for(int i=0; i<V; i++){
            color[i]=-1;
       }
       
       for(int i=0; i<V; i++){
           if(color[i]==-1){
               if(check(i, V, adj, color)==false){
                   return false;
               }
           }
       }
        
        return true;
    }
};

//dfs
