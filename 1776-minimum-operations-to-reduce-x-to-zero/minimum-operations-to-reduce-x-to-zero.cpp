class Solution {
public:
   int minOperations(vector<int>& nums, int totalSum) {
    int n = nums.size();
    long long S = accumulate(nums.begin(), nums.end(), 0LL);
    if (S < totalSum) return -1;
    if (S == totalSum) return n; // pura array remove karna padega

    long long target = S - totalSum;
    unordered_map<long long, int> mp;
    mp[0] = -1; // prefix sum base case

    long long prefix = 0;
    int maxLen = -1;
    for (int i = 0; i < n; i++) {
        prefix += nums[i];
        if (mp.count(prefix - target)) {
            maxLen = max(maxLen, i - mp[prefix - target]);
        }
        if (!mp.count(prefix)) {
            mp[prefix] = i;
        }
    }
    return (maxLen == -1 ? -1 : n - maxLen);
}

};