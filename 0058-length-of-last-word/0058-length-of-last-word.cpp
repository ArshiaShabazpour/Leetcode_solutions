class Solution {
public:
    int lengthOfLastWord(string s) {
        vector<char> buffer;
        bool flag = false; 
        
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] != ' ') {
                flag = true;
                buffer.push_back(s[i]);
            } else if (flag) {
                break;
            }
        }
        
        return buffer.size();
    }
};