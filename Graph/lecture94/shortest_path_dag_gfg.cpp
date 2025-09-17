class Solution {
public:
    // ---------- Topological Sort Helper ----------
    void topoSort(int node, vector<pair<int,int>> adj[], vector<int> &vis, stack<int> &st) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            int v = it.first;
            if (!vis[v]) {
                topoSort(v, adj, vis, st);
            }
        }
        st.push(node);
    }

    // ---------- Shortest Path ----------
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        bool weighted = (edges[0].size() == 3); // if each edge has weight -> DAG approach

        if (!weighted) {
            // ------------------ CASE 1: Unweighted Graph (BFS) ------------------
            vector<int> adj[V];
            for (auto &e : edges) {
                int u = e[0], v = e[1];
                adj[u].push_back(v);
                adj[v].push_back(u); // undirected (if directed, remove this line)
            }

            vector<int> dist(V, 1e9);
            dist[0] = 0; // assume source = 0
            queue<int> q;
            q.push(0);

            while (!q.empty()) {
                int node = q.front(); q.pop();
                for (int neigh : adj[node]) {
                    if (dist[node] + 1 < dist[neigh]) {
                        dist[neigh] = dist[node] + 1;
                        q.push(neigh);
                    }
                }
            }

            for (int i = 0; i < V; i++) if (dist[i] == 1e9) dist[i] = -1;
            return dist;
        } 
        else {
            // ------------------ CASE 2: Weighted DAG (Topo Sort) ------------------
            vector<pair<int,int>> adj[V];
            for (auto &e : edges) {
                int u = e[0], v = e[1], wt = e[2];
                adj[u].push_back({v, wt});
            }

            vector<int> vis(V, 0);
            stack<int> st;
            for (int i = 0; i < V; i++) {
                if (!vis[i]) topoSort(i, adj, vis, st);
            }

            vector<int> dist(V, 1e9);
            dist[0] = 0; // assume source = 0

            while (!st.empty()) {
                int node = st.top(); st.pop();
                if (dist[node] != 1e9) {
                    for (auto it : adj[node]) {
                        int v = it.first, wt = it.second;
                        if (dist[node] + wt < dist[v]) {
                            dist[v] = dist[node] + wt;
                        }
                    }
                }
            }

            for (int i = 0; i < V; i++) if (dist[i] == 1e9) dist[i] = -1;
            return dist;
        }
    }
};