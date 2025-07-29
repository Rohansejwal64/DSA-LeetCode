class Solution {
public:
    vector<string> result;

    void helper(string num, int target, int index, long value, long last,
                string path) {
        // Base case: if we've used all digits
        if (index == num.size()) {
            if (value == target) {
                result.push_back(path);
            }
            return;
        }

        long curr = 0; // current number we're building
        for (int i = index; i < num.size(); i++) {
        curr = curr * 10 + (num[i] - '0');

        // ✅ Stop if number has leading zeros
        if (i > index && num[index] == '0') break;

        if (index == 0) {
            helper(num, target, i + 1, curr, curr, path + to_string(curr));
        } else {
            helper(num, target, i + 1, value + curr, curr, path + "+" + to_string(curr));
            helper(num, target, i + 1, value - curr, -curr, path + "-" + to_string(curr));
            helper(num, target, i + 1, value - last + last * curr, last * curr, path + "*" + to_string(curr));
        }
    }
    }

    vector<string> addOperators(string num, int target) {
        helper(num, target, 0, 0, 0, "");
        return result;
    }
};
