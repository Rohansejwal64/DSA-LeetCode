class Solution {
public:
    int solve(vector<int>& cost,vector<int>& dp,int i){
        int n=cost.size();
       if(i == n-1) return cost[i];   // last step: pay its cost
if(i == n-2) return cost[i];   // second last step: pay its cost

        if(dp[i]!=-1) return dp[i];
        int s1=solve(cost,dp,i+1);
        int s2=solve(cost,dp,i+2);
        return dp[i]=min(s1,s2)+cost[i];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n,-1);
        return min(solve(cost,dp,0),solve(cost,dp,1));
        
    }
};