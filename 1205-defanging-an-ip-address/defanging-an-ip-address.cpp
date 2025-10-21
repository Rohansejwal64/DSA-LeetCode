class Solution {
public:
    string defangIPaddr(string s) {
        string ans;
        for(int i=0;i<s.size();i++){
            if(s[i] != '.'){
                ans.push_back(s[i]);
            }
            else{
                string temp="[.]";
                ans+=temp;
            }
        }
        return ans;
        
    }
};