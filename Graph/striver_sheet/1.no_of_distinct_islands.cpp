https://www.geeksforgeeks.org/problems/number-of-distinct-islands/1

class Solution {
  public:
    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis,
             vector<pair<int,int>>& shape, int baseRow, int baseCol) {
        int n = grid.size();
        int m = grid[0].size();
        
        vis[row][col] = 1;
        // store relative position
        shape.push_back({row - baseRow, col - baseCol});
        
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, -1, 0, 1};
        
        for (int i = 0; i < 4; i++) {
            int newRow = row + delRow[i];
            int newCol = col + delCol[i];
            
            if (newRow >= 0 && newCol >= 0 && newRow < n && newCol < m
                && !vis[newRow][newCol] && grid[newRow][newCol] == 1) {
                dfs(newRow, newCol, grid, vis, shape, baseRow, baseCol);
            }
        }
    }
    
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
        set<vector<pair<int,int>>> st;  // to store unique island shapes
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == 1) {
                    vector<pair<int,int>> shape;
                    dfs(i, j, grid, vis, shape, i, j);
                    st.insert(shape);
                }
            }
        }
        
        return st.size();
    }
};
