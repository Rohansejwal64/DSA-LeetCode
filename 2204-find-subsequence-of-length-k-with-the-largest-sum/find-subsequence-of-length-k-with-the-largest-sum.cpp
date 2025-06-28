class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> v=nums;

        sort(v.begin(),v.end(),greater<int>());
        unordered_map<int,int> visited;
        for(int i=0;i<k;i++){
            visited[v[i]]++;
        }
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(visited[nums[i]]>0){
                ans.push_back(nums[i]);
                visited[nums[i]]--;
                if(ans.size()==k) break;
            }
        }
        return ans;


        
    }
};