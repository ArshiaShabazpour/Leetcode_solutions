class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        string ref = strs[0];

        for (int i = 0; i < ref.size(); i++) {
            char c = ref[i];
            for (int j = 1; j < strs.size(); j++) {
                if (i >= strs[j].size() || strs[j][i] != c) {
                    return ref.substr(0, i);
                }
            }
        }
        return ref;
    }
};
