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
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

        int mini = INT_MAX;
        for (int j = 0; j < n; j++) {
            mini = min(mini, solve(matrix, dp, 0, j));
        }
        return mini;
    }
};