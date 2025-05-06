class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> combos;
        vector<int> combo;
        backtrack(1, n, k, combo, combos);
        return combos;
    }

private:
    void backtrack(int start, int n, int k,
                   vector<int>& combo,
                   vector<vector<int>>& combos) {
        if (combo.size() == k) {
            combos.push_back(combo);
            return;
        }
        for (int i = start; i <= n; ++i) {
            combo.push_back(i);
            backtrack(i + 1, n, k, combo, combos);
            combo.pop_back(); 
        }
    }
};
