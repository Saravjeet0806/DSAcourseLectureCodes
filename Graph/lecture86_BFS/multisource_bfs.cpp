#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    
    queue<pair<int, int>> q;
    vector<vector<int>> dist(m, vector<int>(n, -1));

    // Initialize the queue with all sources (cells with 0)
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == 0) {
                dist[i][j] = 0;
                q.push({i, j});
            }
        }
    }

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    // Standard BFS traversal
    while (!q.empty()) {
        auto [row, col] = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int newRow = row + dx[i];
            int newCol = col + dy[i];

            // Check boundaries and if the cell has not been visited yet
            if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n) {
                if (dist[newRow][newCol] == -1) {
                    dist[newRow][newCol] = dist[row][col] + 1;
                    q.push({newRow, newCol});
                }
            }
        }
    }

    return dist;
}
