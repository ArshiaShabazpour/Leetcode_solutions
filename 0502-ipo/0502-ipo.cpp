class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        k = min(k, n);

        vector<pair<int,int>> projects;
        projects.reserve(n);
        for (int i = 0; i < n; ++i) {
            projects.emplace_back(capital[i], profits[i]);
        }
        sort(projects.begin(), projects.end(),
             [](auto& a, auto& b){ return a.first < b.first; });

        priority_queue<int> maxProfit;
        int idx = 0;

        for (int pick = 0; pick < k; ++pick) {
            while (idx < n && projects[idx].first <= w) {
                maxProfit.push(projects[idx++].second);
            }
            if (maxProfit.empty()) break;

            w += maxProfit.top();
            maxProfit.pop();
        }

        return w;
    }
};
