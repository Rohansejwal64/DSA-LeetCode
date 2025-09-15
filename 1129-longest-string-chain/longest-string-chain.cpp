class Solution {
public:
bool check(string &s1,string &s2){
    if(s1.size()!=1+s2.size()) return false;
    int first=0,second=0;
    while(first<s1.size()){
        if(second<s2.size() && s1[first]==s2[second]) {
            first++;second++;
        }
        else{
            first++;
        }
        
    }
    if(first==s1.size() && second==s2.size()) return true;
    return false;
}
static bool comp(string &s1,string &s2){
    return s1.size()<s2.size();
}
    int longestStrChain(vector<string>& words) {
         sort(words.begin(),words.end(),[](string &s1,string &s2){
            return s1.size()<s2.size();

         });
        int n=words.size();
         vector<int> dp(n, 1);

    int maxLength = 0;
    int lastIndex = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if ((check(words[i],words[j])) && dp[i] < 1 + dp[j]) {
                dp[i] = 1 + dp[j];
            }
        }

        if (dp[i] > maxLength) {
            maxLength = dp[i];
            lastIndex = i;
        }
    }

    
    
    
    
    
    return maxLength;

        
    }
};