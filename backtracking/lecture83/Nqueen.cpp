#include <bits/stdc++.h>
void addSolution(vector<vector<int>> &board, vector<vector<int>> &ans, int n)
{
    vector<int> temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp.push_back(board[i][j]);
        }
    }
    ans.push_back(temp);
}

bool isSafe(int row, int col, vector<vector<int>> &board, int n)
{
    int x = row;
    int y = col;
    // Check for row
    while (y >= 0)
    {
        if (board[x][y] == 1)
        {
            return false;
        }
        y--;
    }

    // Check for diagonal
    x = row;
    y = col;
    while (x >= 0 && y >= 0)
    {
        if (board[x][y] == 1)
        {
            return false;
        }
        x--;
        y--;
    }
    x = row;
    y = col;
    while (x < n && y >= 0)
    {
        if (board[x][y] == 1)
        {
            return false;
        }
        x++;
        y--;
    }
    return true;
}
void solve(int col, vector<vector<int>> &board, vector<vector<int>> &ans, int n)
{
    // Base case
    if (col == n)
    {
        addSolution(board, ans, n);
        return;
    }

    // Solve for each row in the current column

    for (int row = 0; row < n; row++)
    {
        if (isSafe(row, col, board, n))
        {
            // If placing queen is safe
            board[row][col] = 1;
            solve(col + 1, board, ans, n);

            // Backtrack
            board[row][col] = 0;
        }
    }
}
vector<vector<int>> nQueens(int n)
{
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<int>> ans;
    solve(0, board, ans, n);
    return ans;
}










// leetcdoe solution
class Solution {
private:

void addSolution(vector<vector<int>> &board, vector<vector<string>> &ans, int n) {
    vector<string> temp;
    for (int i = 0; i < n; i++) {
        string row;
        for (int j = 0; j < n; j++) {
            row += (board[i][j] == 1) ? "Q" : ".";
        }
        temp.push_back(row);
    }
    ans.push_back(temp);
}

bool isSafe(int row, int col, vector<vector<int>> &board, int n) {
    int x = row;
    int y = col;
    // Check for row
    while (y >= 0) {
        if (board[x][y] == 1) {
            return false;
        }
        y--;
    }

    // Check for diagonal
    x = row;
    y = col;
    while (x >= 0 && y >= 0) {
        if (board[x][y] == 1) {
            return false;
        }
        x--;
        y--;
    }
    x = row;
    y = col;
    while (x < n && y >= 0) {
        if (board[x][y] == 1) {
            return false;
        }
        x++;
        y--;
    }
    return true;
}

void solve(int col, vector<vector<int>> &board, vector<vector<string>> &ans, int n) {
    // Base case
    if (col == n) {
        addSolution(board, ans, n);
        return;
    }

    // Solve for each row in the current column
    for (int row = 0; row < n; row++) {
        if (isSafe(row, col, board, n)) {
            // If placing queen is safe
            board[row][col] = 1;
            solve(col + 1, board, ans, n);

            // Backtrack
            board[row][col] = 0;
        }
    }
}
public:
    vector<vector<string>> solveNQueens(int n) {
     vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<string>> ans;
    solve(0, board, ans, n);
    return ans;
    }
};