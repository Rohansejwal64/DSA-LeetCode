class Solution {
public:
    int solve(vector<int>& coins, int amount,int i,vector<vector<int>> &dp ){
        if(amount==0) return 0;
        if(i==0){
            if(amount%coins[0] !=0) return INT_MAX;
            else{
                return amount/coins[0];
            }
        }

        if(dp[i][amount]!=-1) return dp[i][amount];
        int np=solve(coins,amount,i-1,dp);
        int p=INT_MAX;
        if(amount>=coins[i]){
            int temp=solve(coins,amount-coins[i],i,dp);
            if(temp !=INT_MAX ){
                p=1+solve(coins,amount-coins[i],i,dp);
            }
            
        }
        return dp[i][amount]=min(p,np);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return (solve(coins,amount,n-1,dp)!=INT_MAX ) ?solve(coins,amount,n-1,dp) : -1 ;

    }
};