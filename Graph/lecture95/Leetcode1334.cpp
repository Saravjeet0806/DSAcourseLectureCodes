class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it : edges){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        int bestCity=-1;
        int minReachable = INT_MAX;

        for(int i=0; i<n; i++){
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            vector<int> dist(n, INT_MAX);  
            dist[i] = 0;
            pq.push({0, i});  // (distance, node)

             while (!pq.empty()) {
                int dis = pq.top().first;
                int node = pq.top().second;
                pq.pop();
                
                 for (auto it : adj[node]) {
                    int adjNode = it.first;
                    int edgeWeight = it.second;
                    
                     if (dis + edgeWeight < dist[adjNode]) {
                        dist[adjNode] = dis + edgeWeight;
                        pq.push({dist[adjNode], adjNode});
                      }
                 }
              }

         int reachableCount = 0;
            for (int d : dist) {
                if (d <= distanceThreshold) {
                    reachableCount++;
                }
            }
            
            if (reachableCount < minReachable || (reachableCount == minReachable && i > bestCity)) {
                minReachable = reachableCount;
                bestCity = i;
            }
        }

        return bestCity;
    }
};