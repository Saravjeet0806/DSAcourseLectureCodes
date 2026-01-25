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
    vector<int>adj[V];

    adj[0]={1,2};
    adj[1]={0,3};
    adj[2]={0,4};
    adj[3]={1};
    adj[4]={2};

    vector<int>vis(V, 0);
    vector<int>result;

    dfs(0, adj, vis, result);

    for(auto x : result){
        cout<<x<<endl;
    }

 

return 0;
}