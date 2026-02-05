#include <unordered_map>
#include <list>
#include <stack>

void dfs(int node, unordered_map<int, bool> &vis, stack<int> &st, unordered_map<int, list<int>> &adj)
{
    vis[node] = true;
    for (auto nbr : adj[node])
    {
        if (!vis[nbr])
        {
            dfs(nbr, vis, st, adj);
        }
    }
    // topo
    st.push(node);
}

void revdfs(int node, unordered_map<int, bool> &vis, unordered_map<int, list<int>> &adj)
{
    vis[node] = true;

    for (auto nbr : adj[node])
    {
        if (!vis[nbr])
        {
            revdfs(nbr, vis, adj);
        }
    }
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
    // adjlist
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }
    // toposort
    stack<int> st;
    unordered_map<int, bool> vis;
    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            dfs(i, vis, st, adj);
        }
    }

    // transpose the graph
    unordered_map<int, list<int>> transpose;
    for (int i = 0; i < v; i++)
    {
        vis[i] = 0; // jab dubara dfs call hoga toh sab zero kardo
        for (auto nbr : adj[i])
        {
            transpose[nbr].push_back(i);
        }
    }
    // dfs call using above ordering
    int count = 0;
    while (!st.empty())
    {
        int top = st.top();
        st.pop();
        if (!vis[top])
        {
            count++;
            revdfs(top, vis, transpose);
        }
    }
    return count;
}

https://www.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1
class Solution {
  public:
    void dfs1(int node, vector<int>&vis, vector<vector<int>>&adj, stack<int>&st){
        vis[node]=1;
        
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs1(it, vis, adj, st);
            }
        }
        st.push(node);
    }
    
    void dfs2(int node, vector<int>&vis, vector<vector<int>>&transpose){
        vis[node]=1;
        for(auto it : transpose[node]){
            if(!vis[it]){
                dfs2(it, vis, transpose);
            }
        }
    }
    int kosaraju(vector<vector<int>> &adj) {
        int n = adj.size();
        vector<int>vis(n, 0);
        stack<int>st;
        
        for(int i=0; i<n; i++){
            if(!vis[i]){
                dfs1(i, vis, adj, st);
            }
        }
        
        
        vector<vector<int>>transpose(n);
        
        for(int i=0; i<n; i++){
            for(auto v : adj[i]){
                transpose[v].push_back(i);
            }
        }
        
        fill(vis.begin(), vis.end(), 0); //reset vis
        
        int scc=0;
        
        while(!st.empty()){
            int node = st.top();
            st.pop();
            
            if(!vis[node]){
                dfs2(node, vis, transpose);
                scc++;
            }
        }

        return scc;
    }
};