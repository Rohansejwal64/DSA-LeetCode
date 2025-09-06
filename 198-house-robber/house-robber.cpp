class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
       
        n=nums.size()-1;
        int frwd2=nums[n];
        int frwd1 =max(nums[n],nums[n-1]);
        for(int i=n-2;i>=0;i--){
            int curr=max(nums[i]+frwd2,frwd1);
            frwd2=frwd1;
            frwd1=curr;
        }
        return frwd1;

        
    }
};