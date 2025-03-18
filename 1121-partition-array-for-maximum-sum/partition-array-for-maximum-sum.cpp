class Solution {
public:
int solve(int i,vector<int> &dp,vector<int>& arr, int k){
    int n=arr.size();
    if(i==n) return 0;
    if(dp[i]!=-1) return dp[i];
    int len=0;
    int maxvalue=INT_MIN;
    int maxi=INT_MIN;
    for(int j=i;j<min(n,i+k);j++){
        len++;
        maxvalue=max(maxvalue,arr[j]);
        int sum=(len*maxvalue)+solve(j+1,dp,arr,k);
        maxi=max(maxi,sum);
    }
    return dp[i]=maxi;
}
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n+1,0);
        for(int i=n-1;i>=0;i--){
            int len=0;
         int maxvalue=INT_MIN;
          int maxi=INT_MIN;
          for(int j=i;j<min(n,i+k);j++){
          len++;
          maxvalue=max(maxvalue,arr[j]);
          int sum=(len*maxvalue)+dp[j+1];
          maxi=max(maxi,sum);
           }
      dp[i]=maxi;

        }

        return dp[0];
        
    }
};