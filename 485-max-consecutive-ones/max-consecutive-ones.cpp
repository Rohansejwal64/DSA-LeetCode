class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi=0;
        int cnt=0;
        int i=0;
        while(i<nums.size()){
            if(nums[i]==1){
                cnt++;
                maxi=max(maxi,cnt);
            }
            else{
                cnt=0;
            }
            i++;
        }
        return maxi;
        
    }
};