class Solution
{
	public:
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        set<pair<int, int>>st;
        vector<int>dist(V, 1e9);
        st.insert({0, S});
        dist[S]=0;
        
        while(!st.empty()){
            auto it = *(st.begin());
            int node = it.second;
            int dis = it.first;  //st = (dist, node)
            st.erase(it);
            
            for(auto it : adj[node]){
                int adjNode = it[0]; 
                int edgW = it[1]; 
                
                 if(dis + edgW < dist[adjNode]) {
                    if(dist[adjNode] != 1e9) st.erase({dist[adjNode], adjNode}); 
                    dist[adjNode] = dis + edgW; 
                    st.insert({dist[adjNode], adjNode}); 
                 }
            }
        }
         return dist; 
    }
};

//https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<pair<int,int>>> adj(V);
        for (auto e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});  // remove if directed graph
        }

        // Step 2: Distance array
        vector<int> dist(V, 1e9);
        dist[src] = 0;

        // Step 3: Set -> {distance, node}
        set<pair<int,int>> st;
        st.insert({0, src});

        // Step 4: Dijkstra
        while (!st.empty()) {
            auto it = *(st.begin());
            int dis = it.first;
            int node = it.second;
            st.erase(it);

            for (auto edge : adj[node]) {
                int adjNode = edge.first;
                int edgW = edge.second;

                if (dis + edgW < dist[adjNode]) {
                    // erase old record if exists
                    if (dist[adjNode] != 1e9) {
                        st.erase({dist[adjNode], adjNode});
                    }
                    dist[adjNode] = dis + edgW;
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }

        return dist;
    }
};
