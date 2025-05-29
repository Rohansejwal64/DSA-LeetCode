class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int ans;
        for(int i=0;i<nums.size();i++){
            int index=abs(nums[i])-1;
            if(nums[index]<0){
                ans= index+1;
                break;
            }
            else{
                nums[index]=-nums[index];
            }
        }
        return ans;


        
    }
};