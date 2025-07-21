class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.find(endWord) == wordSet.end()) return 0;

        unordered_set<string> beginSet{beginWord};
        unordered_set<string> endSet{endWord};
        int steps = 1;

        while (!beginSet.empty() && !endSet.empty()) {
            if (beginSet.size() > endSet.size())
                swap(beginSet, endSet);

            unordered_set<string> nextSet;

            for (const string& word : beginSet) {
                string temp = word;
                for (int i = 0; i < temp.size(); ++i) {
                    char originalChar = temp[i];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        temp[i] = c;
                        if (endSet.find(temp) != endSet.end())
                            return steps + 1;
                        if (wordSet.find(temp) != wordSet.end()) {
                            nextSet.insert(temp);
                            wordSet.erase(temp);
                        }
                    }
                    temp[i] = originalChar; 
                }
            }

            beginSet = nextSet;
            steps++;
        }

        return 0;
    }
};