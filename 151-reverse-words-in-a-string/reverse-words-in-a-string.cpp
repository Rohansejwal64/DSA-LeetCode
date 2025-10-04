class Solution {
public:
    string reverseWords(string s) {
        string temp;
        stack<string> st;
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                if(temp.size()==0) continue;
                else{
                    st.push(temp);
                    temp.clear();
                }
            }
            else{
                temp.push_back(s[i]);
            }
        }
        if(temp.size()!=0) st.push(temp);
        string ans;
        while(!st.empty()){
            if(ans.size()!=0){
                ans+=" ";


            }
            ans+=st.top();
            st.pop();

        }
        return ans;

        
    }
};