class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
    vector<int> ans;
    int n = nums.size();
    int lastInserted = -1;

    for (int i = 0; i < n; ++i) {
        if (nums[i] == key) {
            int start = max(i - k, lastInserted + 1);
            int end = min(n - 1, i + k);
            for (int j = start; j <= end; ++j) {
                ans.push_back(j);
            }
            lastInserted = end;
        }
    }

    return ans;
}



};