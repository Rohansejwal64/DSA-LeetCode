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
        int n=s.size();
        int m=t.size();
        vector<vector<int>> dp(n,vector<int>(m,0));



       
       for (int i = 0; i < n; i++) {
        if (s[i] == t[0]) dp[i][0] = 1;
        else if (i > 0) dp[i][0] = dp[i-1][0];  // carry forward
    }

    // Initialize first row
    for (int j = 0; j < m; j++) {
        if (t[j] == s[0]) dp[0][j] = 1;
        else if (j > 0) dp[0][j] = dp[0][j-1];  // carry forward
    }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                 int m=INT_MIN;
                  int nm=INT_MIN;
                 if(s[i]==t[j]){
              m=1+dp[i-1][j-1];
            
                 }
        else{
            nm=max(dp[i-1][j],dp[i][j-1]);
        }
         dp[i][j]=max(m,nm);

            }
        }

        
        return dp[n-1][m-1];
    }
};