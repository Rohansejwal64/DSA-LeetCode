class Solution {
public:
    bool canPartition(vector<int>& arr) {
        int sum=accumulate(arr.begin(), arr.end(),0);
        if( sum %2 !=0) return false;
        int k=sum/2;
        int n=arr.size();
    
        vector<int> dp(k+1,false);
        dp[0]=true;
        if(k>=arr[0]) dp[arr[0]]=1;
    for(int i=1;i<=n-1;i++){
        vector<int> curr(k+1,0);
        curr[0]=1;
        for(int j=1;j<=k;j++){ 
            bool nt=dp[j];
            if(nt==true) curr[j]=1; 
            bool t=false;
            if(j>=arr[i]){ 
                t= dp[j-arr[i]];
            }
            curr[j]=(nt || t);
            }
            dp=curr;
            } 
            
            return dp[k];


        
    }
};