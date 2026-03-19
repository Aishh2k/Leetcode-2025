class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        unordered_set<string> allowed(wordList.begin(), wordList.end());
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        allowed.erase(beginWord);

        while (!q.empty()) {
            auto [word, step] = q.front();
            q.pop();
            if(word == endWord){
                return step;
            }
            for (int i = 0; i < word.size(); i++) {
                string next = word;
                for (char c = 'a'; c <= 'z'; c++) {
                    next[i] = c;
                    if(allowed.count(next)){
                        q.push({next, step+1});
                        allowed.erase(next);
                    }
                }
            }
        }

        return 0;
    }
};