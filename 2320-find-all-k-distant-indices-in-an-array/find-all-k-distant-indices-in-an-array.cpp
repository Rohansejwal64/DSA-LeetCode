class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
    vector<int> keyIndices;
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] == key) {
            keyIndices.push_back(i);
        }
    }

    set<int> resultSet;
    for (int index : keyIndices) {
        int start = max(0, index - k);
        int end = min((int)nums.size() - 1, index + k);
        for (int i = start; i <= end; ++i) {
            resultSet.insert(i);
        }
    }

    return vector<int>(resultSet.begin(), resultSet.end());
}

};