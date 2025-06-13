class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
    int cnt = 0;
    int l = 0, r = 0;
    unordered_map<char, int> mpp;

    for (r = 0; r < n; r++) {
        mpp[s[r]]++;
        
        while (mpp.size() == 3) {
            cnt += (n - r);  // All substrings starting at l and ending at r or further
            mpp[s[l]]--;
            if (mpp[s[l]] == 0) {
                mpp.erase(s[l]);
            }
            l++;
        }
    }
    return cnt;
        
    }
};