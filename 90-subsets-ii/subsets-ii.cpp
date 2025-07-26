class Solution {
public:
    void solve(vector<int>& nums, int i, vector<int>& temp,
               vector<vector<int>>& ans) {
        int n = nums.size();
        while (i < n) {
            
            temp.push_back(nums[i]);
            
            
                ans.push_back(temp);
            

            solve(nums, i + 1, temp, ans);
            temp.pop_back();

            i++;
            while(i>0 && i<n && nums[i]==nums[i-1]) {
                i++;
                
                
            }
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        vector<vector<int>> ans;
        ans.push_back({});
        vector<int> temp;
        sort(nums.begin(),nums.end());
        solve(nums, 0, temp, ans);
        return ans;
    }
};