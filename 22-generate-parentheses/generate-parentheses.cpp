class Solution {
public:
void solve(int &n,string temp, vector<string> &ans,int open,int close){
    if(open==n && close==n){
        ans.push_back(temp);
        return;
    }
    if(open<n){
        solve(n,temp+'(' , ans, open+1,close);
    }
    if(open>close){
        solve(n,temp+')', ans, open, close+1);
    }
}
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        int open=0;
        int close=0;
        solve(n,"",ans,open,close);
        return ans;
        
    }
};