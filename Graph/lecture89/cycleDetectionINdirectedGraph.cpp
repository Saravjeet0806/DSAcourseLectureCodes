#include <unordered_map>
#include <list>
bool checkCycleDFS(int node, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVisited,
                   unordered_map<int, list<int>> &adj)
{
    visited[node] = true;
    dfsVisited[node] = true;

    for (auto neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            bool cycleDetected = checkCycleDFS(neighbour, visited, dfsVisited, adj);
            if (cycleDetected)
                return true;
        }
        else if (dfsVisited[neighbour])
        {
            // visited true    and dfs visited true
            return true;
        }
    }
    dfsVisited[node] = false;
    return false;
}
int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{
    // create adjlist
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].push_back(v);
    }

    // call dfs for all components
    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsVisited;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            bool cyclefound = checkCycleDFS(i, visited, dfsVisited, adj);
            if (cyclefound)
                return true;
        }
    }
    return false;
}

https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
class Solution {
  public:
    bool checkCycleDFS(int node, vector<int> &visited, vector<int> &dfsVisited,
                       unordered_map<int, list<int>> &adj) {
        visited[node] = 1;
        dfsVisited[node] = 1;

        for (auto neighbour : adj[node]) {
            if (!visited[neighbour]) {
                if (checkCycleDFS(neighbour, visited, dfsVisited, adj)) {
                    return true;
                }
            }
            else if (dfsVisited[neighbour]) {
                // back-edge found → cycle
                return true;
            }
        }

        dfsVisited[node] = 0; // backtrack
        return false;
    }

    bool isCyclic(int V, vector<vector<int>> &edges) {
        // Step 1: Build adjacency list
        unordered_map<int, list<int>> adj;
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
        }

        // Step 2: Track visited & dfsVisited arrays
        vector<int> visited(V, 0);
        vector<int> dfsVisited(V, 0);

        // Step 3: DFS for all components
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (checkCycleDFS(i, visited, dfsVisited, adj)) {
                    return true;
                }
            }
        }

        return false;
    }
};
