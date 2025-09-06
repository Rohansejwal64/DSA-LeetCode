class Solution {
public:
   int robLinear(vector<int>& nums, int l, int r) {
        if(l == r) return nums[l];

        int frwd2 = nums[r];
        int frwd1 = max(nums[r], nums[r-1]);
        for(int i = r-2; i >= l; i--) {
            int curr = max(nums[i] + frwd2, frwd1);
            frwd2 = frwd1;
            frwd1 = curr;
        }
        return frwd1;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];

        // Case 1: Exclude first house
        int ans1 = robLinear(nums, 1, n-1);
        // Case 2: Exclude last house
        int ans2 = robLinear(nums, 0, n-2);

        return max(ans1, ans2);
    }
};