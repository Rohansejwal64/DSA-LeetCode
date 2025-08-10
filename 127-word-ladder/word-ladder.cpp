class Solution {
public:
   int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> dict(wordList.begin(), wordList.end());

    if (dict.find(endWord) == dict.end()) return 0; // endWord not in list

    queue<pair<string,int>> q;
    q.push({beginWord, 1});
    dict.erase(beginWord);

    while (!q.empty()) {
        auto [word, steps] = q.front();
        q.pop();

        if (word == endWord) return steps;

        for (int i = 0; i < word.size(); i++) {
            string nextWord = word;
            for (char ch = 'a'; ch <= 'z'; ch++) {
                nextWord[i] = ch;
                if (dict.find(nextWord) != dict.end()) {
                    q.push({nextWord, steps + 1});
                    dict.erase(nextWord);
                }
            }
        }
    }
    return 0; // no transformation found
}

};