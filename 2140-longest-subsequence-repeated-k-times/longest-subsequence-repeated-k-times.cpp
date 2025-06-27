class Solution {
public:
    bool is_subsequence(const string& sub, const string& s, int k) {
        string target = "";
        for (int i = 0; i < k; ++i)
            target += sub;

        int i=0,j = 0;
        while(i<s.size()){
            if(s[i]==target[j]) j++;
            i++;
        }
        return j == target.size();
    }

    string longestSubsequenceRepeatedK(string s, int k) {
        unordered_map<char, int> counts;
        for (char c : s)
            counts[c]++;

        vector<char> hot_chars;
        for (auto& [ch, count] : counts) {
            if (count >= k)
                hot_chars.push_back(ch);
        }

        string ans = "";
        queue<string> q;
        q.push("");

        while (!q.empty()) {
            string curr = q.front();
            q.pop();

            for (char ch : hot_chars) {
                string nxt = curr + ch;
                if (is_subsequence(nxt, s, k)) {
                    if (nxt.size() > ans.size() ||
                        (nxt.size() == ans.size() && nxt > ans))
                        ans = nxt;
                    q.push(nxt);
                }
            }
        }
        return ans;
    }
};