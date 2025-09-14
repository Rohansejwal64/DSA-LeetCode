class Solution {
public:
    int solve(vector<int>& nums,vector<vector<int>> &dp, int i, int pi){
        if(i==nums.size()) return 0;
        if(dp[i][pi+1]!=-1) return dp[i][pi+1];

        int p=0;
        int np=0;

        if(pi==-1 || nums[i]>nums[pi]){
            p=1+solve(nums,dp,i+1,i);
            np=0+solve(nums,dp,i+1,pi);

        }
        else{
            np=0+solve(nums,dp,i+1,pi);
        }
        return dp[i][pi+1]=max(p,np);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));


        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=-1;j--){

                int p=0;
        int np=0;

        if(j==-1 || nums[i]>nums[j]){
            p=1+dp[i+1][i+1];
            np=0+ dp[i+1][j+1] ;

        }
        else{
             np=0+ dp[i+1][j+1] ;
        }
         dp[i][j+1]=max(p,np);

            }
        }
        return dp[0][0];

        
    }
};