class Solution {
public:
    bool canConstruct(const string& ransomNote, const string& magazine) {
        int counts[26] = {0};

        for (char c : magazine) {
            counts[c - 'a']++;
        }

        for (char c : ransomNote) {
            counts[c - 'a']--;
        }

        for (int i = 0; i < 26; i++) {
            if (counts[i] < 0) {
                return false;
            }
        }

        return true;
    }
};