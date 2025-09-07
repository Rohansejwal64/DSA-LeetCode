class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& arr) {
    int m = arr.size();
    int n = arr[0].size();

    if (arr[0][0] == 1 || arr[m-1][n-1] == 1) return 0;

    vector<vector<long long>> dp(m, vector<long long>(n, -1));
    dp[m-1][n-1] = 1;

    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            if (i == m - 1 && j == n - 1) continue; // base case
            if (arr[i][j] == 1) {
                dp[i][j] = 0; // obstacle
                continue;
            }
            long long r = 0, d = 0;
            if (j < n - 1) r = dp[i][j + 1];
            if (i < m - 1) d = dp[i + 1][j];
            dp[i][j] = r + d;
        }
    }

    return (int)dp[0][0]; // if return type must be int, cast back
}

};