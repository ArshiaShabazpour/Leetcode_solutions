class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return 0;

        queue<pair<string,int>> q;
        q.push({beginWord, 1});
        unordered_set<string> visited;
        visited.insert(beginWord);

        while (!q.empty()) {
            auto [word, dist] = q.front(); q.pop();
            if (word == endWord) return dist;

            string next = word;
            for (int i = 0; i < (int)word.size(); ++i) {
                char orig = next[i];
                for (char c = 'a'; c <= 'z'; ++c) {
                    if (c == orig) continue;
                    next[i] = c;
                    if (dict.count(next) && !visited.count(next)) {
                        visited.insert(next);
                        q.push({next, dist + 1});
                    }
                }
                next[i] = orig;
            }
        }
        return 0;
    }
};
