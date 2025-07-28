class Solution {
public:
bool ispalin(string s){
    int i=0;
    int j=s.size()-1;
    while(i<=j){
        if(s[i]!=s[j]) return false;
        i++;
        j--;
    }
    return true;

}
void solve(string s,vector<vector<string>> &ans,vector<string> &temp,int index){
    if(index==s.size()){
        ans.push_back(temp);
        return;
    }
    string st;
    for(int i=index;i<s.size();i++){
        st+=s[i];
        if(ispalin(st)){
            temp.push_back(st);
            solve(s,ans,temp,i+1);
            temp.pop_back();
        }
    }
}
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        solve(s,ans,temp,0);
        return ans;



        
    }
};