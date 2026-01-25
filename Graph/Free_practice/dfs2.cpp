#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int>adj[], vector<int>&vis, vector<int>&result ){
    vis[node]=1;
    result.push_back(node);

    for(int u : adj[node]){
        if(!vis[u]){
            dfs(u, adj, vis, result);
        }
    }
}
int main(){
    int V=5;

    vector<pair<int,int>> edges={
        {0,1}, {0,2}, {1, 3}, {4,2} };


    vector<int>adj[V];

    for(auto e : edges){
        int u = e.first;
        int v = e.second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>vis(V, 0);
    vector<int>result;

    dfs(0, adj, vis, result);

    for(auto x : result){
        cout<<x<<endl;
    }

 

return 0;
}