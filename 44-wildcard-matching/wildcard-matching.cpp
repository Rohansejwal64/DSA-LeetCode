class Solution {
public:
    bool solve(int i, int j, vector<vector<int>> &dp, string &s, string &p) {
    if (i < 0 && j < 0) return true;  // Both strings are exhausted
    if (j < 0) return false;  // Pattern is exhausted, but string remains
    if (i < 0) {  // String is exhausted, check if remaining pattern is only '*'
        for (int k = 0; k <= j; k++) {
            if (p[k] != '*') return false;
        }
        return true;
    }

    if (dp[i][j] != -1) return dp[i][j];

    if (s[i] == p[j] || p[j] == '?') {
        return dp[i][j] = solve(i - 1, j - 1, dp, s, p);
    }

    if (p[j] == '*') {
        return dp[i][j] = solve(i, j - 1, dp, s, p) || solve(i - 1, j, dp, s, p);
    }

    return dp[i][j] = false;
}

bool isMatch(string s, string p) {
    int n = s.size();
    int m = p.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1)); // Corrected size
    return solve(n - 1, m - 1, dp, s, p);
}

};