class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> temp = nums;
        nth_element(temp.begin(), temp.begin() + k - 1, temp.end(),
                    greater<int>());
        int klar = temp[k - 1];
        int cnt = 0;
        for (int i = 0; i < k; i++) {
            if (temp[i] == klar)
                cnt++;
        }
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > klar)
                ans.push_back(nums[i]);
            else if (nums[i] == klar && cnt > 0) {
                ans.push_back(nums[i]);
                cnt--;
            }
            if(ans.size()==k) break;
        }
        return ans;
    }
};