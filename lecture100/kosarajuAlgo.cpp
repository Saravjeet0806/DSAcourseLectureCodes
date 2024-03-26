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