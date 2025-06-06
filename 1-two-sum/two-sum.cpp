class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            
            int a=nums[i];
            int rem=target-a;
            if(mp.find(rem)!=mp.end()){
                ans.push_back(i);
                ans.push_back(mp[rem]);
                break;

            }
            else{
                mp[nums[i]]=i;
            }

        }
        return ans;
        
        
    }
};