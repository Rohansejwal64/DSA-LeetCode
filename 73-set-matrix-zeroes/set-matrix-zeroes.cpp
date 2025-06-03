class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int col0=1;
        
        int r=matrix.size();
        int c=matrix[0].size();
        for (int i = 0; i < r; i++) {
        if (matrix[i][0] == 0) col0 = 0; // ✅ Fix: move this outside inner loop
        for (int j = 1; j < c; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;  // ✅ Remove wrong if-else
            }
        }
    }
        for(int i=c-1;i>=1;i--){
            if(matrix[0][i]==0){
                for(int k=1;k<r;k++){
                    matrix[k][i]=0;
                }
            }
        }
        for(int i=r-1;i>=0;i--){
            if(matrix[i][0]==0){
                for(int k=1;k<c;k++){
                    matrix[i][k]=0;
                }
            }

        }
        if(col0==0){
            for(int i=0;i<r;i++){
                matrix[i][0]=0;
            }
        }
        
    }
};