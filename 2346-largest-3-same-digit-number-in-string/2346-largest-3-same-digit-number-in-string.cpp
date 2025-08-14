class Solution {
public:
    string largestGoodInteger(string num) {
        int best = -1;          // best digit seen that forms a triple (0..9), -1 if none
        int run = 0;            // length of current run of the same digit
        char prev = '\0';       // previous character

        for (char c : num) {
            if (c == prev) {
                ++run;
            } else {
                prev = c;
                run = 1;
            }

            if (run >= 3) {
                int val = c - '0';      
                if (val > best) best = val;
            }
        }

        if (best == -1) return "";
        return string(3, char('0' + best));
    }
};
