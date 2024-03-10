//leetcode solution
class Solution {
public:
bool isSafe(int row, int col, vector<vector<char>>& board, char val) {
    for (int i = 0; i < board.size(); i++) {
        // row check
        if (board[row][i] == val) {
            return false;
        }
        // column check
        if (board[i][col] == val) {
            return false;
        }
        // checking 3x3 matrix
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val) {
            return false;
        }
    }
    return true;
}

bool solve(vector<vector<char>>& board) {
    int n = board.size();

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            // empty cell
            if (board[row][col] == '.') {
                for (char val = '1'; val <= '9'; val++) {
                    if (isSafe(row, col, board, val)) {
                        board[row][col] = val;
                        // check for next cell
                        if (solve(board)) {
                            return true;
                        } else {
                            // backtrack
                            board[row][col] = '.';
                        }
                    }
                }
                return false;  // if solution not possible
            }
        }
    }
    return true;
}

void solveSudoku(vector<vector<char>>& board) {
    solve(board);
}
};


//codestudio solution
bool isSafe(int row, int col, vector<vector<int>>& board, int val){
    for(int i=0; i<board.size(); i++){
        //row check
        if(board[row][i]==val){
            return false;
        }
        //column check
        if(board[i][col]==val)
        return false;
        //checking 3*3 matrix
        if(board[3*(row/3)+i/3][3*(col/3) +i%3]==val)
        return false;
    }
    return true;
}
bool solve (vector<vector<int>>& board){
    int n= board[0].size();

    for(int row=0; row<n; row++){
        for(int col=0; col<n;col++){
            //empty cell
            if(board[row][col]==0){
                for(int val=1; val<=9; val++){
                    if(isSafe(row,col,board,val)){
                        board[row][col]=val;
                        //aage ke liye solution possible?? recursive call
                        bool solutionPossible= solve(board);
                        if(solutionPossible)
                        return true;
                        else {
                            //backtrack
                            board[row][col]=0;
                        }
                        
                    }
                }
                return false;  //if solution not possible
            }

        }
    }
    return true;
}
void solveSudoku(vector<vector<int>>& sudoku)
{
	solve(sudoku);
}