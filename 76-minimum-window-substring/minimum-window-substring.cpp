class Solution {
public:
    string minWindow(string s, string t) {
        int minlen=INT_MAX;
        int Sindex=-1;
        int n=s.size();
        int m=t.size();
        int hash[256]={0};
        for(int j=0;j<m;j++){
                hash[t[j]]++;
            }
            int cnt=0;
            
            int l=0,r=0;
            while(r<n){
                if(hash[s[r]]>0) cnt++;
                hash[s[r]]--;
                while(cnt==m){
                    if(r-l+1<minlen){
                        minlen=r-l+1;
                        Sindex=l;
                    }
                    hash[s[l]]++;
                    if(hash[s[l]]>0) cnt--;
                    l++;
                }
                r++;
            }
       
        if(minlen==INT_MAX){
            return "";
        }
        return s.substr(Sindex,minlen);
        
    }
};