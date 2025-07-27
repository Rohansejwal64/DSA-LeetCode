class Solution {
public:
 void backtrack(vector<int>& candidates, int target, int start, vector<int>& temp, vector<vector<int>>& ans) {
    if (target == 0) {
        ans.push_back(temp);
        return;
    }

    for (int i = start; i < candidates.size(); i++) {
        if (i > start && candidates[i] == candidates[i - 1]) continue; // skip duplicates

        if (candidates[i] > target) break; // pruning (because array is sorted)

        temp.push_back(candidates[i]);
        backtrack(candidates, target - candidates[i], i + 1, temp, ans); // move to next index
        temp.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> ans;
    vector<int> temp;
    backtrack(candidates, target, 0, temp, ans);
    return ans;
}

};