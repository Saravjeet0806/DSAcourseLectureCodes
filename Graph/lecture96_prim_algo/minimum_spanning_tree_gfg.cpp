class Solution {
public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // Step 1: Build adjacency list
        vector<vector<pair<int, int>>> adj(V);
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        // Step 2: Min-heap for (weight, node)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> vis(V, 0);

        pq.push({0, 0}); // {weight, node}
        int sum = 0;

        // Step 3: Prim’s algorithm
        while (!pq.empty()) {
            int node = pq.top().second;
            int wt = pq.top().first;
            pq.pop();

            if (vis[node]) continue;
            vis[node] = 1;
            sum += wt;

            for (auto [adjNode, edW] : adj[node]) {
                if (!vis[adjNode]) {
                    pq.push({edW, adjNode});
                }
            }
        }

        return sum;
    }
};