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
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(s,t,dp,n-1,m-1);
    }
};