class Solution {
public:
void solve(int &n,string temp,vector<string> &ans){
      if(temp.size()==n){
          ans.push_back(temp);
          return;
      }
      solve(n,temp+'1',ans);
      if(temp.empty() || temp[temp.size()-1]=='1'){
          solve(n,temp+'0',ans);
      }
  }
    vector<string> validStrings(int n) {
        vector<string> ans;
        solve(n,"",ans);
        return ans;
        
    }
};