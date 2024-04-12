//memoization solution
class Solution{
private: 
    int solveMem(vector<vector<int>>&mat, int i, int j, int &maxi, vector<vector<int>>&dp){
        if(i>=mat.size() || j>=mat[0].size())
          return 0;
          
         if(dp[i][j]!=-1)
          return dp[i][j];
          
        int right= solveMem(mat, i, j+1, maxi, dp)  ;
        int diagonal=solveMem(mat, i+1, j+1, maxi, dp);
        int down = solveMem(mat, i+1, j, maxi, dp);
        
        if(mat[i][j]==1){
            dp[i][j]= 1+min(right, min(diagonal, down));
            maxi=max(maxi, dp[i][j]);
            return dp[i][j];
        }
        else{
            return dp[i][j]=0;
        }
    }
public:
    int maxSquare(int n, int m, vector<vector<int>> mat){
        int maxi=0;
        vector<vector<int>>dp(n, vector<int>(m, -1));
        solveMem(mat,0,0,maxi,dp);
        return maxi;
    }
};

//tabulation solution
class Solution{
private: 
       int solveTab(vector<vector<int>> &mat, int &maxi){
        int row = mat.size();
        int col = mat[0].size();
        
        vector<vector<int>> dp(row+1, vector<int> (col+1, 0));  //row and col are plused 1 so that they don't go out of bounds
        
        for(int i = row-1; i>=0; i--){
            for(int j = col-1; j>=0; j--){
                
                int right = dp[i][j+1];
                int diagonal = dp[i+1][j+1];
                int down = dp[i+1][j];
                
                if(mat[i][j] == 1){
                    dp[i][j] = 1 + min(right, min(diagonal, down));
                    
                    maxi = max(maxi, dp[i][j]);
                }
                else
                    dp[i][j] = 0;
            }
        }
        
        return 0;
    }
public:
    int maxSquare(int n, int m, vector<vector<int>> mat){
        int maxi = 0;
        solveTab(mat, maxi);
        return maxi;
    }
};