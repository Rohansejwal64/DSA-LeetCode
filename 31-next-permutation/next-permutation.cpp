class Solution {
public:
    void rev(vector<int>& nums, int start){
        int end = nums.size() - 1;
        while(start < end){
            swap(nums[start], nums[end]);
            start++, end--;
        }
    }

    void nextPermutation(vector<int>& nums) {
        int j = nums.size() - 2;

        // Step 1: Find the first decreasing element
        while(j >= 0 && nums[j] >= nums[j + 1]){
            j--;
        }

        if(j >= 0){
            // Step 2: Find the next larger element to swap
            int i = nums.size() - 1;
            while(nums[i] <= nums[j]){
                i--;
            }
            swap(nums[j], nums[i]);
        }

        // Step 3: Reverse the suffix
        rev(nums, j + 1);
    }
};
