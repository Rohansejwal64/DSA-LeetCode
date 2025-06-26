class Solution {
public:
    int longestSubsequence(string s, int k) {
       reverse(s.begin(), s.end());

        int i=0;
        int sum=0;
        int cnt=0;
        for(int j=0;j<s.size();j++){
            if(s[j]=='0'){
                cnt++;
                

            }
            else if(j<31 && (sum+(1<<j) <=k)){
                cnt++;
                sum+=(1 << j );
                
            }
            
            
        }
        return cnt;

        
    }
};