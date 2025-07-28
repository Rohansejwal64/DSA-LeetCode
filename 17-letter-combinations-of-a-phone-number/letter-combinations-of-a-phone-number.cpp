class Solution {
public:
void solve(string digits,vector<string> mp,vector<string> &ans,string &temp,int i){
    
    if(temp.size()==digits.size()){
        ans.push_back(temp);
        return;
    }
    if(i>=digits.size()) return;
    for(char ch: mp[digits[i]-'0']){
        temp.push_back(ch);
        solve(digits,mp,ans,temp,i+1);
        temp.pop_back();


    }

}
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> mp={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> ans;
        string temp;
        solve(digits,mp,ans,temp,0);
        return ans;
        
    }
};