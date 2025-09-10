class Solution {
public:
    int solve(int t, vector<int>& arr,vector<vector<int>> &dp,int i){
        if(t==0) return 1;
        if(i==0){
            if(t%arr[0]==0) return 1;
            else{
                return 0;
            }
        }
        if(dp[i][t]!=-1) return dp[i][t];

        int np=solve(t,arr,dp,i-1);
        int p=0;
        if(arr[i]<=t){
            p=solve(t-arr[i],arr,dp,i);
        }
        return dp[i][t]=np+p;
    }
    int change(int t, vector<int>& arr) {
        int n= arr.size();
        vector<vector<int>> dp(n,vector<int>(t+1,-1));
        return solve(t,arr,dp,n-1);
        
    }
};