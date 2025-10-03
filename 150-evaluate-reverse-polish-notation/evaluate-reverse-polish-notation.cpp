class Solution {
public:
    int stringToInt(const string &s) {
    int num = 0, sign = 1, i = 0;
    if (s[0] == '-') { // handle negative
        sign = -1;
        i = 1;
    }
    for (; i < s.size(); i++) {
        num = num * 10 + (s[i] - '0');
    }
    return num * sign;
}

int evalRPN(vector<string>& tokens) {
    stack<int> st;
    for (auto &token : tokens) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            int a = st.top(); st.pop();
            int b = st.top(); st.pop();
            if (token == "+") st.push(b + a);
            else if (token == "-") st.push(b - a);
            else if (token == "*") st.push(b * a);
            else st.push(b / a);
        } else {
            st.push(stringToInt(token));
        }
    }
    return st.top();
}

};