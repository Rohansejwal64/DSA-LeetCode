class Solution {
public:
    int minSwaps(string s) {

        stack<char> st;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='[') st.push(s[i]);
            else{
                if(st.empty()) st.push(']');
                else if(st.top()=='[') st.pop();
                else{
                    st.push(']');
                }
            }
        }
        int a=0;
        int b=0;
        while(!st.empty()){
            if(st.top()=='['){
                a++;
                
            }
            else{
                b++;
            }
            st.pop();
        }
        int ans=((a+1)/2) + ((b+1)/2);
        return ans/2;
        
    }
};