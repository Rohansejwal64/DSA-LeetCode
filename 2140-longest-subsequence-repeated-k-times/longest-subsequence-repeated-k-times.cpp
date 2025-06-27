class Solution {
public:
    bool is_subsequence(const string& sub, const string& s, int k) {
        string target = "";
        for (int i = 0; i < k; ++i)
            target += sub;

        int j = 0;
        for (char c : s) {
            if (j < target.size() && c == target[j]) {
                ++j;
            }
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

        // Sort in reverse lexicographical order
        // sort(hot_chars.rbegin(), hot_chars.rend()); no need bfs handles it ,
        // see if condition.

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