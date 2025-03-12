class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string buffer;

        // Iterate from end to start of the string
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] != ' ') {
                buffer += s[i];
            } else if (!buffer.empty()) {
                reverse(buffer.begin(), buffer.end());  // reverse the current buffered word
                words.push_back(buffer);
                buffer.clear();
            }
        }

        if (!buffer.empty()) {
            reverse(buffer.begin(), buffer.end());
            words.push_back(buffer);
        }

        string result;
        for (int i = 0; i < words.size(); i++) {
            if (i > 0) result += ' ';
            result += words[i];
        }

        return result;
    }
};
