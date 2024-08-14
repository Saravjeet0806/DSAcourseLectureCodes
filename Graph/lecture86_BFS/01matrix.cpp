Leetcode 
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX)); // Distance matrix
        queue<pair<int, int>> q;

        // Step 1: Initialize the queue with all 0s and set their distance to 0
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 0) {
                    dist[i][j] = 0;
                    q.push({i, j}); // Push the positions of 0s into the queue
                }
            }
        }

        // Step 2: BFS to update distances
        vector<int> dirX = {0, 1, 0, -1};
        vector<int> dirY = {-1, 0, 1, 0};

        while (!q.empty()) {
         int x = q.front().first;
         int y = q.front().second;

            q.pop();

            for (int i = 0; i < 4; ++i) {
                int newX = x + dirX[i];
                int newY = y + dirY[i];

                // Check if the new position is within the bounds and if we can
                // update the distance
                if (newX >= 0 && newX < m && newY >= 0 && newY < n && dist[newX][newY] > dist[x][y] + 1) {
                    dist[newX][newY] = dist[x][y] + 1;
                    q.push({newX, newY});
                }
            }
        }

        return dist;
    }
};

//codestudio 

#include <climits>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> nearest(vector<vector<int>> &mat, int n, int m) {
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX)); // Distance matrix
    queue<pair<int, int>> q;

    // Step 1: Initialize the queue with all 1s and set their distance to 0
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (mat[i][j] == 1) {
                dist[i][j] = 0;
                q.push({i, j}); // Push the positions of 1s into the queue
            }
        }
    }

    // Step 2: BFS to update distances
    vector<int> dirX = {0, 1, 0, -1};
    vector<int> dirY = {-1, 0, 1, 0};

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int newX = x + dirX[i];
            int newY = y + dirY[i];

            // Check if the new position is within the bounds and if we can update the distance
            if (newX >= 0 && newX < n && newY >= 0 && newY < m && dist[newX][newY] > dist[x][y] + 1) {
                dist[newX][newY] = dist[x][y] + 1;
                q.push({newX, newY});
            }
        }
    }

    return dist;
}
