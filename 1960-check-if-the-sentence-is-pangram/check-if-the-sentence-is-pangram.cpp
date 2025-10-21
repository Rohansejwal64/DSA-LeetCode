class Solution {
public:
    bool checkIfPangram(string s) {
        vector<bool> f(26,false);
        for(int i=0;i<s.size();i++){
            int idx=s[i]-'a';
            f[idx]=true;
        }
        for(int i=0;i<26;i++){
            if(f[i]==false){
                return false;
            }
        }
        return true;
        
    }
};