class Solution{
public:
    bool isSafe(int node, int color[], bool graph[101][101], int n, int col) {
            for (int k = 0; k < n; k++) {
                  if (k != node && graph[k][node] == 1 && color[k] == col) {
             // If 'k' is connected to 'node' and has the same color, return false
                  return false;
             }
        }
            return true;
    }
    bool solve(int node, int color [], int m, int n, bool graph [101][101]){
        if(node==n){
            return true;
        }
        for(int i=1; i<=m; i++){
            if(isSafe(node, color, graph, n, i)){
                color[node]=i;
             if (solve(node + 1, color, m, n, graph)) return true;
                  color[node] = 0;
            }
        }
        return false;
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
        int color[n]={0};
        if(solve(0, color, m, n, graph)){
            return true;
        }
        return false;
    }
};