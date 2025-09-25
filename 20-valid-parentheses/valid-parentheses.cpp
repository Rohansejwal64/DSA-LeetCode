class Solution {
public:
char solve( char c){
    if(c==')'){
        return '(';
    }
    else if(c==']'){
        return '[';
    }
    else{
        return '{';
    }
}
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i]== '(' || s[i]== '[' || s[i]== '{'){
                st.push(s[i]);
            }

            else{
                if(st.empty()) return false;
                char ch=solve(s[i]);
                if(st.top()==ch) st.pop();
                else{
                    return false;
                }
            }
        }
        if(!st.empty()) return false;
        return true;
        
    }
};