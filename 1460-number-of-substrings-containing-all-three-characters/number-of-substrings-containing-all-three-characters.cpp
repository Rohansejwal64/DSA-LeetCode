class Solution {
public:
  int numberOfSubstrings(string s) {
    int n = s.size();
    int last[3] = {-1, -1, -1};  // last seen positions for a, b, c
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        last[s[i] - 'a'] = i;
        if (last[0] != -1 && last[1] != -1 && last[2] != -1) {
            cnt += 1 + min({last[0], last[1], last[2]});
        }
    }
    return cnt;
}


};