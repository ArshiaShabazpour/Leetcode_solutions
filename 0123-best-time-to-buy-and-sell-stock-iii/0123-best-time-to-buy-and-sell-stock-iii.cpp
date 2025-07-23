class Solution {
public:
    int maxProfit(vector<int>& prices) {
    if (prices.empty()) return 0;

    std::array<int, 3> dp{};          
    std::array<int, 3> mn;
    mn.fill(prices[0]);

    for (size_t i = 1; i < prices.size(); ++i) {
        for (int k = 1; k <= 2; ++k) {
            mn[k] = std::min(mn[k], prices[i] - dp[k - 1]);
            dp[k] = std::max(dp[k], prices[i] - mn[k]);
        }
    }
    return dp[2];
    }
};