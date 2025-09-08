class Solution {
public:
    bool isCyclic(int V, vector<vector<int>>& edges) {
        // Step 1: Build adjacency list
        vector<vector<int>> adj(V);
        vector<int> indegree(V, 0);

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);   // u -> v
            indegree[v]++;         // increment indegree of v
        }

        // Step 2: Put all nodes with indegree 0 in queue
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // Step 3: Process nodes
        int count = 0;  // number of processed nodes
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;

            for (auto neighbor : adj[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // Step 4: If not all nodes processed, cycle exists
        return count != V;
    }
};
