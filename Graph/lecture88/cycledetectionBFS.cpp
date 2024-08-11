#include <unordered_map>
#include <queue>
#include <list>
bool isCyclicBFS(int src, unordered_map<int,bool> &visited,  unordered_map <int,list<int>> &adj){
 unordered_map<int,int> parent;
 parent[src]=-1;
 visited[src]=1;
 queue<int> q;
 q.push(src);

 while(!q.empty()){
     int front=q.front();
     q.pop();

     for(auto neighbour: adj[front]){
         if(visited[neighbour]==true && neighbour !=parent[front]){
             return true;
         }
         else if(!visited[neighbour]){
            q.push(neighbour);
            visited[neighbour]=1;
            parent[neighbour]=front;
         }
     }
 }
 return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    //create adjacency list
    unordered_map <int,list<int>>adj;
    for(int i=0; i<m; i++){
        int u=edges[i][0];
        int v=edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    //to handle disconnected components
    unordered_map<int,bool> visited;
    for(int i=0; i<n; i++){
        if(!visited[i]){
            bool ans= isCyclicBFS(i, visited, adj);
            if(ans==1)
                return "Yes";   
        }
    }
    return "No";
}


//geeksforgeeks
bool bfs(int start, vector<int> adj[], unordered_set<int>& visited) {
    queue<pair<int, int>> q; // (current_node, parent_node)
    q.push({start, -1});
    visited.insert(start);

    while (!q.empty()) {
        int current = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (int neighbor : adj[current]) {
            if (visited.find(neighbor) == visited.end()) {
                visited.insert(neighbor);
                q.push({neighbor, current});
            } else if (neighbor != parent) {
                return true;
            }
        }
    }
    return false;
}

bool isCycle(int V, vector<int> adj[]) {
    unordered_set<int> visited;
    for (int vertex = 0; vertex < V; ++vertex) {
        if (visited.find(vertex) == visited.end()) {
            if (bfs(vertex, adj, visited)) {
                return true;
            }
        }
    }
    return false;
}


//another approach
class Solution {
  private: 
  bool detect(int src, vector<int> adj[], int vis[]) {
      vis[src] = 1; 
      // store <source node, parent node>
      queue<pair<int,int>> q; 
      q.push({src, -1}); 
      // traverse until queue is not empty
      while(!q.empty()) {
          int node = q.front().first; 
          int parent = q.front().second; 
          q.pop(); 
          
          // go to all adjacent nodes
          for(auto adjacentNode: adj[node]) {
              // if adjacent node is unvisited
              if(!vis[adjacentNode]) {
                  vis[adjacentNode] = 1; 
                  q.push({adjacentNode, node}); 
              }
              // if adjacent node is visited and is not it's own parent node
              else if(parent != adjacentNode) {
                  // yes it is a cycle
                  return true; 
              }
          }
      }
      // there's no cycle
      return false; 
  }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // initialise them as unvisited 
        int vis[V] = {0};
        for(int i = 0;i<V;i++) {
            if(!vis[i]) {
                if(detect(i, adj, vis)) return true; 
            }
        }
        return false; 
    }
};