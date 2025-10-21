class Solution {
public:
    bool rotateString(string s, string g) {
        if(s==g) return true;
        int n=s.size();
        int cnt=1;
        while(cnt<n){
            char temp=s[0];
            s.erase(s.begin());
            s.push_back(temp);
             if(s==g) return true;
             cnt++;


            
        }
        return false;

        
    }
};