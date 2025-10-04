class Solution {
public:
    string reverseWords(string s) {
        string temp;
        for (int i = 0; i < s.size(); i++) {
            if(s[i]!=' ') temp+=s[i];
            else{
                if(!temp.empty() && temp.back()!=' ')temp+=s[i];
            }
        }
        if(temp.size()!=0 && temp.back()==' ') temp.pop_back();

        reverse(temp.begin(),temp.end());
        int st=0;
        for(int i=0;i<=temp.size();i++){
            if(temp[i]==' ' || i==temp.size()){
                reverse(temp.begin()+st, temp.begin()+i);
                st=i+1;
            }
        }
        return temp;
    }
};