class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> dp(n,-1);
        n=nums.size()-1;
        dp[n]=nums[n];
        dp[n-1]=max(nums[n],nums[n-1]);
        for(int i=n-2;i>=0;i--){
            dp[i]=max(nums[i]+dp[i+2],dp[i+1]);
        }
        return dp[0];

        
    }
};