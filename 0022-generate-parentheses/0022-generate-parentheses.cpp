class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> patterns;
        string pattern = "(";
        backtrack(pattern,patterns,1,1,n);
        return patterns;
    }
    void backtrack(string pattern, vector<string>& patterns, int n, int k,int brackets){
    if(pattern.length() == brackets*2){
        patterns.push_back(pattern);
        return;
    }
    if(n > 0){
        backtrack(pattern + ")", patterns, n - 1, k,brackets);
    }
    if(k <= brackets-1){
        backtrack(pattern + "(", patterns, n + 1, k + 1,brackets);
    }
}

};