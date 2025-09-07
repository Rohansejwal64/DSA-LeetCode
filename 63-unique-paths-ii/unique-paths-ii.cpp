class Solution {
public:
int solve(vector<vector<int>>& arr, int i, int j, vector<vector<int>> &dp){
      int m=dp.size();
      int n=dp[0].size();
      if(i>=m || j>=n || arr[i][j]==1) return 0;
      if(i==m-1 && j==n-1) return 1;
      
      if(dp[i][j]!=-1) return dp[i][j];
      
      int r=solve(arr,i,j+1,dp);
      int d=solve(arr,i+1,j,dp);
      return dp[i][j]=r+d;
  }
    int uniquePathsWithObstacles(vector<vector<int>>& arr) {
        int m=arr.size();
        int n=arr[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(arr,0,0,dp);
        
    }
};