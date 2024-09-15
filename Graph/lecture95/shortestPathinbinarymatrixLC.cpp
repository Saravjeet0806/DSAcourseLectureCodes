class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if (grid[0][0] != 0 || grid[n-1][n-1] != 0) {
            return -1; //endpoint blocked or start is blocked
        }
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {1, 1}, {0, -1}, {-1, 0}, {-1, -1}, {1, -1}, {-1, 1}}; 
        //possible diections include diagonals
         queue<pair<int, int>> q;
         q.push({0,0});
         grid[0][0]=1; //visited so mark it 1

         while(!q.empty()){
            auto [x, y] = q.front();
            int distance = grid[x][y];
            q.pop();
            if (x == n - 1 && y == n - 1) {
                return distance;
            }
             for (auto [dx, dy] : directions) { //iterates 8 directions
                int newX = x + dx;
                int newY = y + dy;

                // Check if the new position is valid and unvisited (i.e., grid[newX][newY] == 0)
                if (newX >= 0 && newX < n && newY >= 0 && newY < n && grid[newX][newY] == 0) {
                    q.push({newX, newY});
                    grid[newX][newY] = distance + 1; // mark as visited with the distance from the start
                }
            }
         }
         return -1;
    }
};