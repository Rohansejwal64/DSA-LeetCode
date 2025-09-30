class Solution {
public:
    int minAddToMakeValid(string s) {
    int open = 0, close = 0;
    for (char c : s) {
        if (c == '(') {
            open++;
        } else { // c == ')'
            if (open > 0) {
                open--; // match with a previous '('
            } else {
                close++; // extra ')'
            }
        }
    }
    return open + close;
}

};