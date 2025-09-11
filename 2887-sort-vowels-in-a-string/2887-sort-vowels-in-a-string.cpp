class Solution {
public:
    string sortVowels(string s) {
        unordered_map<char, int> vowels = {
            {'A',0},{'E',0},{'I',0},{'O',0},{'U',0},
            {'a',0},{'e',0},{'i',0},{'o',0},{'u',0}
        };

        for (char c : s) {
            if (vowels.find(c) != vowels.end()) {
                vowels[c]++;
            }
        }

        vector<char> keys = {'A','E','I','O','U','a','e','i','o','u'};
        
        int k = 0;

        for (int i = 0; i < s.size(); i++) {
            if (vowels.find(s[i]) != vowels.end()) {
                while (vowels[keys[k]] == 0) {
                    k++;
                }
                s[i] = keys[k];
                vowels[keys[k]]--;
            }
        }
        return s;
    }
};