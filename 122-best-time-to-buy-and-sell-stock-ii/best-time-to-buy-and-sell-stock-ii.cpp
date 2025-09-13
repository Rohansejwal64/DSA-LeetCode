class Solution {
public:
    int solve(vector<int>& prices,vector<vector<int>> &dp,int i,int buy){

        if(i>=prices.size()) return 0;

        if(dp[i][buy]!=-1) return dp[i][buy];
        int profit=0;

        if(buy){
            profit=max(-prices[i]+solve(prices,dp,i+1,0), solve(prices,dp,i+1,1));

        }
        else{
            profit=max(prices[i]+solve(prices,dp,i+1,1), solve(prices,dp,i+1,0));
        }
        return dp[i][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return solve(prices,dp,0,1);
        
    }
};