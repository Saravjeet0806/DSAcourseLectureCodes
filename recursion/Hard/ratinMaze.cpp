class Solution {
  public:
    void solve(int i, int j, vector<vector<int>>& maze, int n, string path, vector<string>& ans, vector<vector<int>>& visited) {
        // Base case: reached destination
        if (i == n - 1 && j == n - 1) {
            ans.push_back(path);
            return;
        }

        // Directions: D, L, R, U
        string directions = "DLRU";
        int dx[] = {1, 0, 0, -1};
        int dy[] = {0, -1, 1, 0};

        for (int dir = 0; dir < 4; dir++) {
            int new_i = i + dx[dir];
            int new_j = j + dy[dir];
            char move = directions[dir];

            // Check if within bounds, not visited, and path is not blocked
            if (new_i >= 0 && new_j >= 0 && new_i < n && new_j < n &&
                !visited[new_i][new_j] && maze[new_i][new_j] == 1) {
                visited[i][j] = 1;
                solve(new_i, new_j, maze, n, path + move, ans, visited);
                visited[i][j] = 0; // backtrack
            }
        }
    }

    vector<string> ratInMaze(vector<vector<int>>& maze) {
        int n = maze.size();
        vector<string> ans;

        if (maze[0][0] == 0 || maze[n - 1][n - 1] == 0)
            return ans; // no path if start or end is blocked

        vector<vector<int>> visited(n, vector<int>(n, 0));
        solve(0, 0, maze, n, "", ans, visited);

        sort(ans.begin(), ans.end()); // lexicographically sorted
        return ans;
    }
};
