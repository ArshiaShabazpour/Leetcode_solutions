class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (beginWord == endWord) 
            return 1;

        bool found = false;
        for (const auto& w : wordList) {
            if (w == endWord) {
                found = true;
                break;
            }
        }
        if (!found) 
            return 0;

        queue<pair<string,int>> q;
        q.push({beginWord, 1}); 

        while (!q.empty()) {
            auto [word, length] = q.front();
            q.pop();

            for (int i = 0; i < wordList.size(); ++i) {
                int diff = 0;
                for (int j = 0; j < word.size(); ++j) {
                    if (wordList[i][j] != word[j]) {
                        ++diff;
                        if (diff > 1) 
                            break;
                    }
                }
                if (diff == 1) {
                    if (wordList[i] == endWord) 
                        return length + 1;

                    q.push({wordList[i], length + 1});

                    wordList[i] = wordList.back();
                    wordList.pop_back();
                    --i;  
                }
            }
        }

        return 0; 
    }
};