class Solution {
public:
void solve(vector<int>& candidates, int sum, int i, int &target,vector<int> &temp,vector<vector<int>> &ans ){
    if(sum>target) return;
    if(sum==target) ans.push_back(temp);
    temp.push_back(candidates[i]);
    solve(candidates,sum+candidates[i],i,target,temp,ans);
    temp.pop_back();
    i++;
    for(int index=i;index<candidates.size();index++){
         temp.push_back(candidates[index]);
         solve(candidates,sum+candidates[index],index,target,temp,ans);
         temp.pop_back();


    }
    
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(candidates,0,0,target,temp,ans);
        return ans;
        
    }
};