class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        sort(nums.begin(),nums.end());
        int curcnt=0;
        int prvsmall=INT_MIN;
        int largest=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]-1==prvsmall){
                curcnt++;
                prvsmall=nums[i];
            }
            else if(nums[i]!=prvsmall){
                curcnt=1;
                prvsmall=nums[i];
            }
            largest=max(largest,curcnt);


        }
        return largest;

        
    }
};