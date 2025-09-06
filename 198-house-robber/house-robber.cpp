class Solution {
public:
int solve(vector<int>& nums,vector<int>& dp,int i){
    if(i>=nums.size()) return 0;
    if(dp[i]!=-1) return dp[i];
    int p=nums[i]+solve(nums,dp,i+2);
    int np=solve(nums,dp,i+1);
    return dp[i]=max(p,np);
}
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);

        return solve(nums,dp,0);
        
    }
};