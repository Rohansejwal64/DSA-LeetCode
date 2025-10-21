class Solution {
public:
    string sortVowels(string s) {
        string vowels = "AEIOUaeiou";
        vector<char> v;

        // Step 1: Collect all vowels
        for (char c : s)
            if (vowels.find(c) != string::npos)
                v.push_back(c);

        // Step 2: Sort vowels by ASCII order
        sort(v.begin(), v.end());

        // Step 3: Replace vowels in original order
        int j = 0;
        for (int i = 0; i < s.size(); i++) {
            if (vowels.find(s[i]) != string::npos) {
                s[i] = v[j++];
            }
        }

        return s;
    }
};