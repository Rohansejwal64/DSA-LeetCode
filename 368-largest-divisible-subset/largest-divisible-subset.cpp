class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
       sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int> dp(n,1);
        int maxi=0;
        int li=0;
        vector<int> bck(n,0);
        for(int i=0;i<n;i++){
            bck[i]=i;
            for(int j=0;j<i;j++){
                if(nums[i] % nums[j]==0 ){
                    if(dp[i]<1+dp[j]){
                        dp[i]=max(dp[i],1+dp[j]);
                        bck[i]=j;

                    }
                    
                }
            }
            if(maxi<dp[i]){
                maxi=max(maxi,dp[i]);
                 li=i;


            }
            
        }

        vector<int> ans;
        ans.push_back(nums[li]);
        
        while(bck[li]!=li){
            ans.push_back(nums[bck[li]]);
            li=bck[li];
        }

        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};