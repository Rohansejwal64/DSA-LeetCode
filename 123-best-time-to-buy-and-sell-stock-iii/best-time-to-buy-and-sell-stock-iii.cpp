class Solution {
public:
int solve(vector<int>& prices,vector<vector<vector<int>>> &dp,int i,int buy, int p){

        if(i>=prices.size()) return 0;
        if(p==0) return 0;

        if(dp[i][buy][p]!=-1) return dp[i][buy][p];
        int profit=0;

        if(buy){
            profit=max(-prices[i]+solve(prices,dp,i+1,0,p), solve(prices,dp,i+1,1,p));

        }
        else{
            profit=max(prices[i]+solve(prices,dp,i+1,1,p-1), solve(prices,dp,i+1,0,p));
        }
        return dp[i][buy][p]=profit;
    }
    int maxProfit(vector<int>& prices) {
         vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(prices,dp,0,1,2);
        
    }
};