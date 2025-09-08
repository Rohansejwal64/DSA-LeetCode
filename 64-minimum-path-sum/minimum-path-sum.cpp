class Solution {
public:
int solve(int m,int n,vector<vector<int>> &dp,vector<vector<int>> &grid){
    if(m==0 && n==0) return grid[m][n];
    if(m<0 || n<0) return INT_MAX;
    if(dp[m][n]!=-1) return dp[m][n];
    int up=solve(m-1,n,dp,grid);
    int left=solve(m,n-1,dp,grid);
    return dp[m][n]=min(up,left)+grid[m][n];
}
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        dp[0][0]=grid[0][0];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) continue;
                int up=INT_MAX,left=INT_MAX;
                if(i>0){
                    up=dp[i-1][j];
                }
                if(j>0){
                    left=dp[i][j-1];
                }
                dp[i][j]=min(up,left)+grid[i][j];
            }
        }
        return dp[m-1][n-1];
        
    }
};