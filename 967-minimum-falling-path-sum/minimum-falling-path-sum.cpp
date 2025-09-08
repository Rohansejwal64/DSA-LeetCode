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
        vector<int> dp=matrix[n-1];
       
        for(int i=n-2;i>=0;i--){
            vector<int> curr(n);
            for(int j=n-1;j>=0;j--){
                int d = dp[j];
                int ld = (j > 0) ? dp[j-1] : INT_MAX;
                int rd = (j < n-1) ? dp[j+1] : INT_MAX;
                curr[j] = matrix[i][j] + min(d, min(ld, rd));

            }
            dp=curr;
        }

        
        return *min_element(dp.begin(),dp.end());
    }
};