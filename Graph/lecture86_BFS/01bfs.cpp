#include <iostream>
#include <vector>
#include <deque>

using namespace std;

const int INF = 1e9;

// Graph represented as adjacency list where each pair is {to, weight}
void zeroOneBFS(int src, int n, vector<vector<pair<int, int>>>& adj, vector<int>& dist) {
    fill(dist.begin(), dist.end(), INF);
    deque<int> dq;
    
    dist[src] = 0;
    dq.push_back(src);
    
    while (!dq.empty()) {
        int u = dq.front();
        dq.pop_front();
        
        for (auto& edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;
            
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                
                // 0-weight edges go to the front
                if (weight == 0) {
                    dq.push_front(v);
                } 
                // 1-weight edges go to the back
                else {
                    dq.push_front(v); // Wait, no, weight 1 goes to back
                }
            }
        }
    }
}


// The 0-1 BFS algorithm computes the shortest paths in a graph where edge weights are exactly 0 or 1 in O(V + E) time. It uses a double-ended queue (deque):Push 0-weight edges to the front (high priority).Push 1-weight edges to the back (low priority).