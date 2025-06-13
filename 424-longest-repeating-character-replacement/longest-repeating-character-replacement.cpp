class Solution {
public:
   int characterReplacement(string s, int k) {
    int l = 0, r = 0, maxCount = 0, maxLen = 0;
    int freq[26] = {0};
    int n = s.size();
    
    for (r = 0; r < n; r++) {
        freq[s[r] - 'A']++;
        maxCount = max(maxCount, freq[s[r] - 'A']);
        
        while ((r - l + 1) - maxCount > k) {
            freq[s[l] - 'A']--;
            l++;
        }
        
        maxLen = max(maxLen, r - l + 1);
    }
    
    return maxLen;
}


};