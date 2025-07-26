class Solution {
public:
void solve(int n, string &temp, vector<string> &ans, int open, int close) {
    if (open == n && close == n) {
        ans.push_back(temp);
        return;
    }
    
    if (open < n) {
        temp.push_back('(');
        solve(n, temp, ans, open + 1, close);
        temp.pop_back();  // undo
    }
    
    if (close < open) {
        temp.push_back(')');
        solve(n, temp, ans, open, close + 1);
        temp.pop_back();  // undo
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> ans;
    string temp;
    solve(n, temp, ans, 0, 0);
    return ans;
}

};