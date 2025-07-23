class Solution {
public:
    int maxProfit(int n, const std::vector<int>& prices) {
        int m = prices.size();
        if (m == 0 || n == 0) return 0;
        n = std::min(n, m / 2);

        std::vector<int> dp(n + 1, 0);
        std::vector<int> mn(n + 1, prices[0]);

        for (int i = 1; i < m; ++i) {
            for (int k = 1; k <= n; ++k) {
                mn[k] = std::min(mn[k], prices[i] - dp[k - 1]);
                dp[k] = std::max(dp[k], prices[i] - mn[k]);
            }
        }
        return dp[n];
    }
};
