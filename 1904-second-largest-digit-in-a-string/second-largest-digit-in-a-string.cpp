class Solution {
public:
    int secondHighest(string s) {
        vector<int> digits;
        int flag=0;
        for(int i=0;i<s.size();i++){
            if(s[i]>=48 &&s[i]<=57){
                flag=1;
                digits.push_back(s[i]-48);

            }
        }
        if(flag==0) return -1;
        int lar=digits[0];
        int slar=-1;
        for(int i=1;i<digits.size();i++){
            if(digits[i]>lar){
                slar=lar;
                lar=digits[i];
            }
            else if(digits[i]<lar && digits[i]>slar){
                slar=digits[i];
            }
        }
        return slar;
        
    }
};