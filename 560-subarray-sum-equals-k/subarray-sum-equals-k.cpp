class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
    unordered_map<int, int> mp;
    mp[0] = 1;  // base case: subarray starting from index 0
    int sum = 0, ans = 0;

    for(int i = 0; i < arr.size(); i++) {
        sum += arr[i];

        // Check how many times (sum - k) has occurred
        if(mp.find(sum - k) != mp.end()) {
            ans += mp[sum - k];
        }

        // Add/update the current prefix sum in map
        mp[sum]++;
    }

    return ans;
}

};