class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int n = words.size();
        int i = 0;
        
        while (i < n) {
            int j = i;
            int lineLength = 0;
            while (j < n && lineLength + words[j].size() + (j - i) <= maxWidth) {
                lineLength += words[j].size();
                j++;
            }
            
            int numWords = j - i;
            int totalSpaces = maxWidth - lineLength;
            string line;
            
            if (j == n || numWords == 1) {
                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k < j - 1) {
                        line.push_back(' ');
                    }
                }
                line.append(maxWidth - line.size(), ' ');
            } else {
                int spacePerGap = totalSpaces / (numWords - 1);
                int extraSpaces = totalSpaces % (numWords - 1);
                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k < j - 1) {
                        int spacesToApply = spacePerGap + (extraSpaces > 0 ? 1 : 0);
                        extraSpaces--;
                        line.append(spacesToApply, ' ');
                    }
                }
            }
            result.push_back(line);
            i = j;
        }
        return result;
    }
};
