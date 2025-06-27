class Solution {
public:
    int maxProduct(vector<int>& nums) {
         int n = nums.size();
    int maxProd = nums[0];
    int leftProd = 1, rightProd = 1;

    for (int i = 0; i < n; ++i) {
        leftProd = (leftProd == 0 ? 1 : leftProd) * nums[i];
        rightProd = (rightProd == 0 ? 1 : rightProd) * nums[n - 1 - i];
        maxProd = max({maxProd, leftProd, rightProd});
    }

    return maxProd;
    }
};