class Solution {
public:
    void topoSort(int node, vector<pair<int,int>> adj[], vector<int>& vis, stack<int>& st) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            int v = it.first;
            if (!vis[v]) {
                topoSort(v, adj, vis, st);
            }
        }
        st.push(node);
    }

    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // Step 1: Build adjacency list
        vector<pair<int,int>> adj[V];
        for (int i = 0; i < E; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
        }

        // Step 2: Topological Sort
        vector<int> vis(V, 0);
        stack<int> st;
        for (int i = 0; i < V; i++) {
            if (!vis[i]) topoSort(i, adj, vis, st);
        }

        // Step 3: Distance initialization
        vector<int> dist(V, 1e9);
        dist[0] = 0;   // source is always 0

        // Step 4: Relax edges in topo order
        while (!st.empty()) {
            int node = st.top();
            st.pop();

            if (dist[node] != 1e9) { // only relax if node is reachable
                for (auto it : adj[node]) {
                    int v = it.first;
                    int wt = it.second;
                    if (dist[node] + wt < dist[v]) {
                        dist[v] = dist[node] + wt;
                    }
                }
            }
        }

        // Step 5: Convert unreachable (1e9) → -1
        for (int i = 0; i < V; i++) {
            if (dist[i] == 1e9) dist[i] = -1;
        }

        return dist;
    }
};
