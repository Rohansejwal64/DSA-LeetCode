class Solution {
public:
   int myAtoi(string s) {
    long long ans = 0;
    bool isPositive = true;
    int i = 0;

    // Skip spaces
    while (i < s.size() && s[i] == ' ') i++;

    // Check sign
    if (i < s.size() && (s[i] == '-' || s[i] == '+')) {
        if (s[i] == '-') isPositive = false;
        i++;
    }

    // Process digits
    while (i < s.size() && s[i] >= '0' && s[i] <= '9') {
        int digit = s[i] - '0';

        // Check overflow before multiplying
        if (ans > (INT_MAX - digit) / 10) {
            return isPositive ? INT_MAX : INT_MIN;
        }

        ans = ans * 10 + digit;
        i++;
    }

    return isPositive ? ans : -ans;
}
};