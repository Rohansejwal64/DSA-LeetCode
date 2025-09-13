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
        vector<vector<int>> dp(prices.size()+1,vector<int>(2,0));

        for(int i=prices.size()-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                int profit=0;

        if(j){
            profit=max(-prices[i]+dp[i+1][0], dp[i+1][1] );

        }
        else{
            profit=max( prices[i]+dp[i+1][1], dp[i+1][0] );
        }
         dp[i][j]=profit;

            }
        }







        return dp[0][1];
        
    }
};