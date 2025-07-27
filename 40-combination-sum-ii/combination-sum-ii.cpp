class Solution {
public:
 void backtrack(vector<int>& candidates, int target, int start, vector<int>& temp, vector<vector<int>>& ans) {
    if (target == 0) {
        ans.push_back(temp);
        return;
    }
    if (target < 0) return;



    for (int i = start; i < candidates.size(); i++) {
        temp.push_back(candidates[i]);
        
        backtrack(candidates, target - candidates[i], i+1, temp, ans); // allow reuse
        temp.pop_back();
        while(i+1<candidates.size() && candidates[i]==candidates[i+1])i++;
    }
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
    vector<int> temp;
    sort(candidates.begin(),candidates.end());
    backtrack(candidates, target, 0, temp, ans);
    return ans;
    }
};