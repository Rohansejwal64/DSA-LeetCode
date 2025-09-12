class Solution {
public:
    int solve(string &s, string &t,vector<vector<int>> &dp,int i,int j){
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int m=INT_MIN;
        int nm=INT_MIN;
        if(s[i]==t[j]){
            m=1+solve(s,t,dp,i-1,j-1);
            
        }
        else{
            nm=max(solve(s,t,dp,i-1,j),solve(s,t,dp,i,j-1));
        }
        return dp[i][j]=max(m,nm);
    }
    int longestCommonSubsequence(string s, string t) {
    int n = s.size();
    int m = t.size();
    
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(s[i-1] == t[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}
};