class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int i=0;
        int n=nums.size();
        while(i+1<n){
            if(nums[i]!=nums[i+1]) return nums[i];
            i+=2;
        }
        return nums[i];
        
    }
};