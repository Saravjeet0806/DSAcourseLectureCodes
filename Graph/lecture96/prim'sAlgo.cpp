#include <bits/stdc++.h>
// prim s algo gfg 
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
       	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
       	vector<int>vis(V, 0);
       	pq.push({0,0}); //wt,node
       	int sum=0;
       	while(!pq.empty()){
       	    int node = pq.top().second;
       	    int wt = pq.top().first;
       	    pq.pop();
       	    
       	    if(vis[node]) continue;
       	    vis[node]=1;
       	    sum+=wt;
       	    for(auto it : adj[node]){
       	        int adjNode = it[0];
       	        int edW = it[1];
       	        if(!vis[adjNode]){
       	            pq.push({edW, adjNode});
       	        }
       	    }
       	}
       	return sum;
    }
    
};


vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    unordered_map<int, list<pair<int, int>>> adj;
    for (int i = 0; i < g.size(); i++)
    {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    vector<int> key(n + 1);
    vector<int> mst(n + 1);
    vector<int> parent(n + 1);

    for (int i = 0; i <= n; i++)
    {
        key[i] = INT_MAX;
        parent[i] = -1;
        mst[i] = false;
    }

    // algo
    key[1] = 0;
    parent[1] = -1;

    for (int i = 1; i < n; i++)
    {
        int mini = INT_MAX;
        int u;
        // find mini node
        for (int v = 1; v <= n; v++)
        {
            if (mst[v] == false && key[v] < mini)
            {
                u = v;
                mini = key[v];
            }
        }

        // mark min node as true
        mst[u] = true;
        // check its adjacent nodes;

        for (auto it : adj[u])
        {
            int v = it.first;
            int w = it.second;
            if (mst[v] == false && w < key[v])
            {
                parent[v] = u;
                key[v] = w;
            }
        }
    }
    vector<pair<pair<int, int>, int>> result;
    // loop ko 2 se chalao because 1 ka parent -1 hai
    for (int i = 2; i <= n; i++)
    {
        result.push_back({{parent[i], i}, key[i]});
    }
    return result;
}
