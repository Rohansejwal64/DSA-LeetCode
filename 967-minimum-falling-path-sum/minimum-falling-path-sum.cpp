class Solution {
public:
    int solve(vector<vector<int>>& matrix, vector<vector<int>>& dp, int i, int j) {
        int n = matrix.size();

        // boundary check
        if (j < 0 || j >= n) return INT_MAX;

        // base case: last row
        if (i == n - 1) return matrix[i][j];

        // already computed
        if (dp[i][j] != INT_MAX) return dp[i][j];

        int d  = solve(matrix, dp, i + 1, j);
        int ld = solve(matrix, dp, i + 1, j - 1);
        int rd = solve(matrix, dp, i + 1, j + 1);

        return dp[i][j] = matrix[i][j] + min(d, min(ld, rd));
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp = matrix;
        for(int i=n-2;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                int d = dp[i+1][j];
                int ld = (j > 0) ? dp[i+1][j-1] : INT_MAX;
                int rd = (j < n-1) ? dp[i+1][j+1] : INT_MAX;
                dp[i][j] = matrix[i][j] + min(d, min(ld, rd));

            }
        }

        
        return *min_element(dp[0].begin(),dp[0].end());
    }
};