//easy o(n*m) and 0(n+m)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<bool> rows(n, false), cols(m, false);

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]==0){
                    rows[i]=true;
                    cols[j]=true;
                }
            }
        }

         for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(rows[i]||cols[j]){
                    matrix[i][j]=0;
                }
            }
         }
    }
};

//o(n*m) and constant time space complexity
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<bool> rows(n, false), cols(m, false);

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]==0){
                    rows[i]=true;
                    cols[j]=true;
                }
            }
        }

         for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(rows[i]||cols[j]){
                    matrix[i][j]=0;
                }
            }
         }
    }
};