class Solution {
public:
   string reverseWords(string s) {
    // Step 1: Remove extra spaces and trim
    string temp;
    for (char c : s) {
        if (c != ' ') temp += c;
        else if (!temp.empty() && temp.back() != ' ') temp += ' ';
    }
    if (!temp.empty() && temp.back() == ' ') temp.pop_back();

    // Step 2: Reverse the entire string
    reverse(temp.begin(), temp.end());

    // Step 3: Reverse each word
    int start = 0;
    for (int i = 0; i <= temp.size(); i++) {
        if (i == temp.size() || temp[i] == ' ') {
            reverse(temp.begin() + start, temp.begin() + i);
            start = i + 1;
        }
    }

    return temp;
}
};