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
       vector<int> temp(n,INT_MAX);
       
        for(int i=0;i<m;i++){
            vector<int> curr(n,INT_MAX);
            for(int j=0;j<n;j++){
                if(i==0 && j==0) {
                    curr[0]=grid[0][0];
                    continue;
                }
                int up=INT_MAX,left=INT_MAX;
                if(i>0){
                    up=temp[j];
                }
                if(j>0){
                    left=curr[j-1];
                }
               curr[j]=min(up,left)+grid[i][j];
            }
            temp=curr;
        }
        return temp[n-1];
        
    }
};