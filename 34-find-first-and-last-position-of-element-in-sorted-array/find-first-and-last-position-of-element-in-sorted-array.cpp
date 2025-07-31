class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int st=0;
        int end=nums.size()-1;
        int si=-1;
        while(st<=end){
            int mid=st+(end-st)/2;
            if(nums[mid]==target){
                si=mid;
                end=mid-1;
            }
            else if(nums[mid]>target){
                end=mid-1;
            }
            else{
                st=mid+1;
            }
        }
        if(si==-1){
            return {-1,-1};
        }
        int ei=si;
        while(ei<nums.size()-1 && nums[ei]==nums[ei+1] ) ei++;
        return {si,ei};
        
    }
};