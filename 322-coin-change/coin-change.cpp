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
        vector<vector<int>> dp(n,vector<int>(amount+1,INT_MAX));


        for(int i=0;i<n;i++){
            dp[i][0]=0;

        }
        for(int i=1;i<=amount;i++){
            if(i%coins[0]==0){
                dp[0][i]=i/coins[0];
            }
        }

        for(int i=1;i<n;i++){
            for(int j=1;j<=amount;j++){
                int np=dp[i-1][j] ;
                  int p=INT_MAX;
                if(j>=coins[i]){
                     int temp=dp[i][j-coins[i]];
                      if(temp !=INT_MAX ){
                         p=1+temp;
                     }
            
             }
         dp[i][j]=min(p,np);

            }
        }





        return (dp[n-1][amount]!=INT_MAX ) ?dp[n-1][amount] : -1 ;

    }
};