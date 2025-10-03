class Solution {
public:
   int evalRPN(vector<string>& tokens) {
    stack<int> st;
    
    for (auto &token : tokens) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            int a = st.top(); st.pop();  // right operand
            int b = st.top(); st.pop();  // left operand
            if (token == "+") st.push(b + a);
            else if (token == "-") st.push(b - a);
            else if (token == "*") st.push(b * a);
            else st.push(b / a);
        } else {
            int num = 0, sign = 1, i = 0;
            if (token[0] == '-') {  // handle negative numbers
                sign = -1;
                i = 1;
            }
            for (; i < token.size(); i++) {
                num = num * 10 + (token[i] - '0');
            }
            st.push(num * sign);
        }
    }
    
    return st.top();
}

};