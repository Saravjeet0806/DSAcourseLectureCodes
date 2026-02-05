#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
int getchild(int node, vector<int> &parent)
{
    int cnt = 0;
    for (int i = 0; i < 5; i++)
    {
        if (parent[i] == node)
            cnt++;
    }

    return cnt;
}
void dfs(int node, vector<bool> &ans, int &timer, vector<int> &parent, vector<int> &disc, vector<int> &low, vector<bool> &vis, unordered_map<int, vector<int>> &adj)
{
    vis[node] = true;
    low[node] = timer;
    disc[node] = timer;
    timer++;
    for (auto nbr : adj[node])
    {
        if (nbr == parent[node])
            continue;
        if (!vis[nbr])
        {
            parent[nbr] = node;
            dfs(nbr, ans, timer, parent, disc, low, vis, adj);
            // while return update low
            low[node] = min(low[node], low[nbr]);
            // check for articulation point
            if (low[nbr] >= disc[node] && parent[node] != -1)
            {
                ans[node] = true;
            }
        }
        else
        {
            // check back edge update low
            low[node] = min(low[node], disc[nbr]);
        }
    }

    if (parent[node] == -1 && getchild(node, parent) > 1)
    {

        ans[node] = true;
    }
}
int main()
{
    int v = 5;
    int e = 5;
    vector<pair<int, int>> edges;
    edges.push_back(make_pair(0, 3));
    edges.push_back(make_pair(3, 4));
    edges.push_back(make_pair(0, 4));
    edges.push_back(make_pair(0, 1));
    edges.push_back(make_pair(1, 2));

    unordered_map<int, vector<int>> adj;
    // making adj
    for (int i = 0; i < e; i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // creating 4 data struct
    vector<int> parent(v);
    vector<int> low(v);
    vector<int> disc(v);
    vector<bool> vis(v);

    vector<bool> ans(v);
    int timer = 0;

    // iniailize all data struct
    for (int i = 0; i < v; i++)
    {
        parent[i] = -1;
        low[i] = 0;
        disc[i] = 0;
        vis[i] = false;
    }
    // itearte all vertex
    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            dfs(i, ans, timer, parent, disc, low, vis, adj);
        }
    }
    // ans
    cout << "Articulation Nodes are:->" << endl;

    for (int i = 0; i < v; i++)
    {

        if (ans[i] == true)
            cout << i << " ";
    }
    return 0;
}

//https://www.geeksforgeeks.org/problems/articulation-point-1/1

class Solution {
  private:
  int timer=0;
    void dfs(int node, int parent, vector<int> &vis, int desc[], int low[], vector<int>&mark, vector<int>adj[]){
        vis[node] =1;
        desc[node] = low[node] = timer++;
        int child = 0;
        
        for(auto it : adj[node]){
            if(it==parent) continue;
            
            if(!vis[it]){
                dfs(it, node, vis, desc, low, mark, adj);
                low[node] = min(low[node], low[it]);
                
                if(low[it]>= desc[node] && parent!=-1){
                    mark[node]=1;
                }
                child++;
            }
            else{
                low[node]=min(low[node], desc[it]);
            }
        }
        
        if(parent==-1 && child>1){
            mark[node]=1;
        }
    }
  public:
    vector<int> articulationPoints(int V, vector<int> adj[]) {
        vector<int> vis(V, 0), mark(V, 0);
        int desc[V], low[V];
        
        for(int i=0; i<V; i++){
            if(!vis[i]){
                dfs(i, -1, vis, desc, low, mark, adj);
            }
        }
        
        vector<int>ans;
        for(int i=0; i<V; i++){
            if(mark[i]) ans.push_back(i);
        }
        
        return ans.empty() ? vector<int>{-1} : ans;
        
    }
};