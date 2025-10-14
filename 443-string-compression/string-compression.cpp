class Solution {
public:
    int compress(vector<char>& s) {
    int i = 0;
    string res;

    while (i < s.size()) {
        int j = i;
        while (j < s.size() && s[i] == s[j]) {  // ✅ add missing condition
            j++;
        }

        res.push_back(s[i]);  // ✅ always push the current char

        int count = j - i;    // ✅ actual count of this char
        if (count > 1) {
            res += to_string(count);  // ✅ append count as string
        }

        i = j;  // ✅ move to next character group
    }

    // ✅ overwrite s with compressed result
    for (int k = 0; k < res.size(); k++) {
        s[k] = res[k];
    }

    return res.size();  // ✅ return new length
}
};