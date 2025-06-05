class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
         int n=nums.size();
        vector<int> ans;
        int val=(n/3)+1;
        unordered_map<int, int> mp;
        for(int i=0;i<n;i++){
            
            
                mp[nums[i]]++;
                if(mp[nums[i]]==val){
                    ans.push_back(nums[i]);
                }
                
            
        } 
        // for(auto v:mp){
        //     if(v.second>n/3){
        //         ans.push_back(v.first);
        //     }
        // }
        return ans;
        
    }
};