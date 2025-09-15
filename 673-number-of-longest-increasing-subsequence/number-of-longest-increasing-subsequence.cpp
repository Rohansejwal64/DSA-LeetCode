class Solution {
public:
    int findNumberOfLIS(std::vector<int>& arr) {
    int n = arr.size();
    if (n <= 1) {
        return n;
    }

    // dp[i] = length of LIS ending at index i
    std::vector<int> dp(n, 1);
    // count[i] = number of LIS of length dp[i] ending at index i
    std::vector<int> count(n, 1);

    int maxLength = 1;

    // Populate dp and count arrays
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j]) {
                // Found a longer LIS ending at i
                if (dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    count[i] = count[j]; // Inherit the count from the previous element
                }
                // Found another LIS of the same length ending at i
                else if (dp[j] + 1 == dp[i]) {
                    count[i] += count[j]; // Add the new paths
                }
            }
        }
        // Keep track of the max length found so far
        maxLength = std::max(maxLength, dp[i]);
    }

    // Sum up the counts of all subsequences that have the maxLength
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (dp[i] == maxLength) {
            ans += count[i];
        }
    }

    return ans;
}
};