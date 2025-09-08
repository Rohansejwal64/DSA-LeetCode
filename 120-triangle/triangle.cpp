class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    vector<int> dp(triangle[n-1].size(),-1);

    // Initialize the last row
    for (int i = 0; i < triangle[n-1].size(); i++) {
        dp[i] = triangle[n-1][i];
    }

    // Bottom-up DP
    for (int i = n-2; i >= 0; i--) {
        for (int j = 0; j <=i; j++) {
            dp[j] = triangle[i][j] + min(dp[j], dp[j+1]);
        }
    }

    return dp[0];
}
};