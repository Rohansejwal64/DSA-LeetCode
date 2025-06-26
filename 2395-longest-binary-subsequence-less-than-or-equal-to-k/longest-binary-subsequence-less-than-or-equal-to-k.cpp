class Solution {
public:
    int longestSubsequence(string s, int k) {
      int sum = 0, cnt = 0, n = s.size();
for (int j = n - 1, bit = 0; j >= 0; --j) {
    if (s[j] == '0') {
        cnt++;
    }
    else if (bit < 31 && sum + (1 << bit) <= k) {
        sum += (1 << bit);
        cnt++;
    }
    bit++;
}
return cnt;


        
    }
};