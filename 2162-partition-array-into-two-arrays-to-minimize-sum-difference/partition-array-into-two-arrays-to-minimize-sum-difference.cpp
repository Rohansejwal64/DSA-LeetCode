class Solution {
public:
vector<vector<int>> generateSubsetSums(const vector<int>& a) {
    int m = a.size();
    vector<vector<int>> sums(m + 1);
    sums[0].push_back(0); // Base case: a sum of 0 is possible with 0 elements.

    for (int num : a) {
        // Iterate backwards to avoid using the same element multiple times in one step.
        for (int k = m - 1; k >= 0; --k) {
            for (int s : sums[k]) {
                sums[k + 1].push_back(s + num);
            }
        }
    }
    return sums;
}
    int minimumDifference(vector<int>& arr) {
        int n=arr.size();


       if (n % 2 != 0) {
        return -1; // Or throw an exception
    }
    if (n == 0) {
        return 0;
    }

    int totalSum = accumulate(arr.begin(), arr.end(), 0);
    int halfSize = n / 2;

    // --- Meet-in-the-Middle Approach ---

    // 1. Split the array into two halves.
    vector<int> first_half(arr.begin(), arr.begin() + halfSize);
    vector<int> second_half(arr.begin() + halfSize, arr.end());

    // 2. Generate all possible sums for each half.
    vector<vector<int>> sums1 = generateSubsetSums(first_half);
    vector<vector<int>> sums2 = generateSubsetSums(second_half);

    int minDifference = 1e9;

    // 3. Combine sums from both halves to find the minimum difference.
    // We need to pick 'k' elements from the first half and 'halfSize - k' from the second.
    for (int k = 0; k <= halfSize; ++k) {
        vector<int>& s1_list = sums1[k];
        vector<int>& s2_list = sums2[halfSize - k];
        
        if (s1_list.empty() || s2_list.empty()) continue;

        // Sort the second list to allow for efficient binary searching.
        sort(s2_list.begin(), s2_list.end());

        for (int s1 : s1_list) {
            // We want the total sum of one subset (s1 + s2) to be close to totalSum / 2.
            // So, the target for s2 is (totalSum / 2) - s1.
            int target_s2 = (totalSum / 2) - s1;

            // Find the sum in s2_list closest to our target.
            auto it = lower_bound(s2_list.begin(), s2_list.end(), target_s2);

            // Check the element at the found position.
            if (it != s2_list.end()) {
                int s2 = *it;
                minDifference = min(minDifference, abs(totalSum - 2 * (s1 + s2)));
            }
            // Check the element just before the found position, as it might be closer.
            if (it != s2_list.begin()) {
                int s2 = *(--it);
                minDifference = min(minDifference, abs(totalSum - 2 * (s1 + s2)));
            }
        }
    }

    return minDifference;
        
    }
};