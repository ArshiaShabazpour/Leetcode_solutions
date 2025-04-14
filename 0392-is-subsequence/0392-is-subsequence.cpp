class Solution {
public:
    bool isSubsequence(string s, string t) {
        int counter = 0;
        for (char c : t) {
            if (counter < s.size() && s[counter] == c) {
                counter++;
            }
        }
        return counter == s.size();
    }
};
