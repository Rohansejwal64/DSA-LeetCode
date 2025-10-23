class Solution {
public:
void getLPSLength(string &s,vector<int> &ans) {
        // code here
        int n=s.size();
       
        int px=0;
        int sx=1;
        while(sx<n){
            if(s[px]==s[sx]){
                ans[sx]=px+1;
                sx++;
                px++;
                
            }
            else{
                if(px==0){
                    ans[sx]=0;
                    sx++;
                }
                else{
                    px=ans[px-1];
                    
                }
            }
        }
        
    }
    int strStr(string haystack, string needle) {
        int n=haystack.size();
        int m=needle.size();
        if(m>n) return -1;
        vector<int> ans(m,0);
        getLPSLength(needle,ans);
        
        
        int f=0;
        int s=0;
        while(f<n && s<m){
            if(haystack[f]==needle[s]){
                f++;
                s++;
            }
            else{
                if(s==0){
                    f++;
                }
                else{
                    int idx=ans[s-1];
                    s=idx;
                }
            }
        }
        if(s>=m){
            return f-s;
        }
        else{
            return -1;
        }


        
    }
};