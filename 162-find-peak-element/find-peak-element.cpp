class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int i=0;
        while(i+1<nums.size()){
            if(nums[i]>nums[i+1]) return i;
            i++;

        }
        return i;
        
    }
};