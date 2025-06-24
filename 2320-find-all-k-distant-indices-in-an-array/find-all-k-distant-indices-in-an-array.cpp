class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
    int n = nums.size();
    vector<bool> mark(n, false);

    for (int i = 0; i < n; ++i) {
        if (nums[i] == key) {
            int start = max(0, i - k);
            int end = min(n - 1, i + k);
            for (int j = start; j <= end; ++j) {
                mark[j] = true;
            }
        }
    }

    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        if (mark[i]) ans.push_back(i);
    }

    return ans;
}


};