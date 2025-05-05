class Solution {
public:
    string simplifyPath(const string& path) {
        vector<string> st;
        int n = path.size();
        for (int i = 0; i < n; ) {
            while (i < n && path[i] == '/') ++i;
            if (i == n) break;
            
            int start = i;
            while (i < n && path[i] != '/') ++i;
            string comp = path.substr(start, i - start);
            
            if (comp == ".") {
            } else if (comp == "..") {
                if (!st.empty()) {
                    st.pop_back();
                }
            } else {
                st.push_back(comp);
            }
        }
        if (st.empty()) return "/";
        string result;
        for (const string& dir : st) {
            result += "/" + dir;
        }
        return result;
    }
};