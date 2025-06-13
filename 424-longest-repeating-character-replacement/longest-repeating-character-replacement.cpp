class Solution {
public:
    int characterReplacement(string s, int k) {
    int l = 0, r = 0, maxCount = 0, maxLen = 0;
    map<char, int> mpp;
    int n = s.size();
    
    for (r = 0; r < n; r++) {
        mpp[s[r]]++;
        maxCount = max(maxCount, mpp[s[r]]);
        
        while ((r - l + 1) - maxCount > k) {
            mpp[s[l]]--;
            l++;
        }
        
        maxLen = max(maxLen, r - l + 1);
    }
    
    return maxLen;
}

};