#include <bits/stdc++.h>

void topoSort(int node, vector<bool> &visited, stack<int> &s, unordered_map<int, list<int>> &adj)
{

    visited[node] = 1;

    for (auto neighbour : adj[node])
    {
        if (!visited[neighbour])
            topoSort(neighbour, visited, s, adj);
    }
    // after returning from call push in stack
    s.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{
    // adjency list
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < e; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    // call dfs topological sort until function for all components
    //  unordered_map<int, bool> visited;
    stack<int> s;
    vector<bool> visited(v, 0);
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
            topoSort(i, visited, s, adj);
    }

    vector<int> ans;
    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}

https://www.geeksforgeeks.org/problems/topological-sort/1
class Solution {
  public:
  
    void dfs(int node, vector<vector<int>>& adj, vector<int>& visited, stack<int>& st) {
        visited[node] = 1;
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited, st);
            }
        }
        // Once all neighbors are done, push this node
        st.push(node);
    }
   
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
       
        // Step 1: Build adjacency list
        vector<vector<int>> adj(V);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
        }
        
        // Step 2: Visited array
        vector<int> visited(V, 0);
        stack<int> st;
        
        // Step 3: Call DFS on all unvisited nodes
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, adj, visited, st);
            }
        }
        
        // Step 4: Pop from stack to get topo order
        vector<int> topo;
        while (!st.empty()) {
            topo.push_back(st.top());
            st.pop();
        }
        
        return topo;
        
    }
};