 bool compareByIndex(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;  // sort by original index
}
class Solution {
public:
   

vector<int> maxSubsequence(vector<int>& nums, int k) {
    vector<pair<int, int>> v;
    for (int i = 0; i < nums.size(); i++) {
        v.push_back({nums[i], i});  // pair of (value, index)
    }

    // Step 1: Sort by value descending
    sort(v.begin(), v.end(), [](pair<int, int>& a, pair<int, int>& b) {
        return a.first > b.first;
    });

    // Step 2: Pick top k and sort by original index
    vector<pair<int, int>> topK(v.begin(), v.begin() + k);
    sort(topK.begin(), topK.end(), compareByIndex);

    // Step 3: Extract values
    vector<int> ans;
    for (auto& p : topK) {
        ans.push_back(p.first);
    }

    return ans;
}

};