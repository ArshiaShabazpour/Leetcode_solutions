#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<bool> broken(26, false);
        for (char c : brokenLetters) broken[c - 'a'] = true;

        int count = 0;
        istringstream iss(text);
        string word;
        while (iss >> word) {                
            bool ok = true;
            for (char c : word) {
                if (broken[c - 'a']) {      
                    ok = false;
                    break;
                }
            }
            if (ok) ++count;
        }
        return count;
    }
};
