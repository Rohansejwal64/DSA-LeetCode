class Solution {
public:
    string addStrings(string s1, string s2) {
        int idx1=s1.size()-1;
        int idx2=s2.size()-1;
        string ans;
        int carry=0;
        while(idx1>=0 && idx2>=0){
            int c1=s1[idx1]-'0';
            int c2=s2[idx2]-'0';
            int res=c1+c2+carry;
            carry=res/10;
            res=res%10;
            ans+=to_string(res);
            idx1--;
            idx2--;



        }
        while(idx1>=0){
            int c1=s1[idx1]-'0';
            int res=c1+carry;
            carry=res/10;
            res=res%10;
            ans+=to_string(res);
            idx1--;
            



        }
        while(idx2>=0){
            int c2=s2[idx2]-'0';
            int res=c2+carry;
            carry=res/10;
            res=res%10;
            ans+=to_string(res);
            idx2--;
            



        }
        if(carry>0){
            ans+=to_string(carry);
        }
        reverse(ans.begin(),ans.end());
        return ans;

        
    }
};