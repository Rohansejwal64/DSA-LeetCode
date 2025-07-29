class Solution {
public:
     vector<string> result;

    void helper(const string &num, int target, int index, long value, long last, string &path) {
        if (index == num.size()) {
            if (value == target) result.push_back(path);
            return;
        }

        long curr = 0;
        int pathLen = path.size(); // for backtracking efficiently

        for (int i = index; i < num.size(); i++) {
            curr = curr * 10 + (num[i] - '0');

            // ✅ Stop if number has leading zeros
            if (i > index && num[index] == '0') break;

            string currStr = to_string(curr);

            if (index == 0) {
                // First number: no operator before
                path.append(currStr);
                helper(num, target, i + 1, curr, curr, path);
                path.resize(pathLen); // backtrack
            } else {
                // Add '+'
                path.push_back('+');
                path.append(currStr);
                helper(num, target, i + 1, value + curr, curr, path);
                path.resize(pathLen);

                // Add '-'
                path.push_back('-');
                path.append(currStr);
                helper(num, target, i + 1, value - curr, -curr, path);
                path.resize(pathLen);

                // Add '*'
                path.push_back('*');
                path.append(currStr);
                helper(num, target, i + 1, value - last + last * curr, last * curr, path);
                path.resize(pathLen);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        result.clear();
        string path;
        path.reserve(num.size() * 2); // reserve space for speed
        helper(num, target, 0, 0, 0, path);
        return result;
    }
};
