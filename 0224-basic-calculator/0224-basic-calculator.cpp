class Solution {
public:
    int doDepth(const std::string& s, int& idx) {
        int sum = 0;
        int n = s.length();

        while (idx < n && s[idx] != ')') {
            if (s[idx] == '(') {
                idx++;  
                sum += doDepth(s, idx);
                idx++;  
            } else if (s[idx] == '+' || s[idx] == '-') {
                char op = s[idx++];
                if (s[idx] == '(') {
                    idx++;  
                    int val = doDepth(s, idx);
                    idx++;  
                    sum += (op == '+') ? val : -val;
                } else {
                    int num = 0;
                    while (idx < n && isdigit(s[idx])) {
                        num = num * 10 + (s[idx++] - '0');
                    }
                    sum += (op == '+') ? num : -num;
                }
            } else if (isdigit(s[idx])) {
                int num = 0;
                while (idx < n && isdigit(s[idx])) {
                    num = num * 10 + (s[idx++] - '0');
                }
                sum += num;
            }
        }

        return sum;
    }

    int calculate(std::string s) {
        s.erase(remove(s.begin(), s.end(), ' '), s.end());
        int idx = 0;
        return doDepth(s, idx);
    }
};
