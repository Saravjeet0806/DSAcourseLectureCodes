class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();
        // (up, left, down, right)

        vector<int> dirX = {-1, 0, 1, 0};
        vector<int> dirY = {0, -1, 0, 1};

        // Mark the current cell as visited (convert to water)
        grid[i][j] = 0;
        // Explore the four directions (up, left, down, right)
        for (int d = 0; d < 4; d++) {
            int newX = i + dirX[d];
            int newY = j + dirY[d];

            // Check boundary conditions and continue DFS if it's a valid land
            // cell
            if (newX >= 0 && newX < m && newY >= 0 && newY < n &&
                grid[newX][newY] == 1) {
                dfs(grid, newX, newY);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    if (grid[i][j] == 1)
                        dfs(grid, i, j);
                }
            }
        }
        int enclaveCount = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    enclaveCount++;
                }
            }
        }

        return enclaveCount;
    }
};